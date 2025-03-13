#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

bool is_leap_year(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}

std::string incrementDate(std::string date)
{
    int day = std::atoi(date.substr(8, date.length()).c_str()) + 1;
    if (day > 32 || day < 1)
        throw 0;
    int month = std::atoi(date.substr(5, 7).c_str());
    if (month < 0 || month > 12)
        throw 0;
    int year = std::atoi(date.substr(0, 4).c_str());
    if (year > 2022 || year < 2009)
        throw 0;
    if (day == 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    {
        day = 1;
        if (month == 12)
        {
            month = 0;
            ++year;
        }
        else
            ++month;
    }
    else if (day == 31 && month != 2)
    {
        day = 1;
        ++month;
    }
    else if ((day == 29 && month == 2) || (day == 30 && month == 2 && is_leap_year(year)))
    {
        day = 1;
        ++month;
    }
    std::ostringstream os_year;
    os_year << year;
    std::string s_year = os_year.str();
    std::ostringstream os_month;
    os_month << month;
    std::string s_month = os_month.str();
    if (s_month.size() == 1)
        s_month.insert(s_month.begin(), '0');
    std::ostringstream os_day;
    os_day << day;
    std::string s_day = os_day.str();
    if (s_day.size() == 1)
        s_day.insert(s_day.begin(), '0');
    return s_year + "-" + s_month + "-" + s_day;
}

std::string decrementDate(std::string date)
{
    int day = std::atoi(date.substr(8, date.length()).c_str()) - 1;
    int month = std::atoi(date.substr(5, 7).c_str());
    int year = std::atoi(date.substr(0, 4).c_str());
    if (day == 0 && (month - 1 == 1 || month - 1 == 3 || month - 1 == 5 || month - 1 == 7 || month - 1 == 8 || month - 1 == 10 || month == 1))
    {
        day = 31;
        if (month == 1)
        {
            month = 12;
            --year;
        }
        else
            --month;
    }
    else if (day == 0 && month != 3)
    {
        if (is_leap_year(year))
            day = 29;
        else
            day = 28;
    }
    else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
    {
        day = 30;
        --month;
    }
    std::ostringstream os_year;
    os_year << year;
    std::string s_year = os_year.str();
    std::ostringstream os_month;
    os_month << month;
    std::string s_month = os_month.str();
    if (s_month.size() == 1)
        s_month.insert(s_month.begin(), '0');
    std::ostringstream os_day;
    os_day << day;
    std::string s_day = os_day.str();
    if (s_day.size() == 1)
        s_day.insert(s_day.begin(), '0');
    return s_year + "-" + s_month + "-" + s_day;
}

std::string correctDate(std::string date, std::map<std::string, double> csv)
{
    int i = 0;
    std::string date1 = date;
    while (csv.find(date) == csv.end())
    {
        date = incrementDate(date);
        ++i;
    }
    int x = 0;
    while (csv.find(date1) == csv.end())
    {
        date1 = decrementDate(date1);
        ++x;
    }
    if (x < i)
        return date1;
    return date;
}

void BitcoinExchange::PrintData()
{
    std::string buffer;
    std::ifstream infile(this->input_file.c_str());
    std::string date;
    std::string trash;

    if (!infile.is_open())
    {
        std::cout << "Error opening the file\n";   
        return ;
    }
    std::getline(infile, trash, '\n');
    std::cout << trash << "\n";
    while (!infile.eof())
    {
        try
        {
            std::getline(infile, buffer, '\n');
            if (buffer.find('|') == std::string::npos)
                throw 0;
            date = buffer.substr(0, buffer.find('|') - 1);
            if (csv.find(date) == csv.end())
                date = correctDate(date, csv);
            std::cout << buffer.substr(0, buffer.find('|')).substr(0, buffer.find(' ') + 1) << "=>";
            buffer = buffer.substr(buffer.find('|') + 1, buffer.length());
            if (atof(buffer.c_str()) < 0)
            {
                std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b";
                throw 1;
            }
            if (atof(buffer.c_str()) >= 2147483648)
            {
                std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b";
                throw 2;
            }
            for (unsigned long i = 0; i < buffer.size(); i++)
                if (!isdigit(buffer[i]) && buffer[i] != '.' && buffer[i] != ' ')
                {
                    std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b";
                    throw 0;
                }
            int last_space = 0;
            while (buffer[last_space] == ' ')
                last_space++;
            buffer = buffer.substr(last_space - 1, buffer.length());
            std::cout << buffer;
            std::cout << " = " << this->csv[date] * atof(buffer.c_str()) << "\n";
        }
        catch (int i)
        {
            if (i == 0)
                std::cout << "Error: Bad Input\n";
            else if (i == 1)
                std::cout << "Error: not a positive number\n";
            else if (i == 2)
                std::cout << "Error: too large a number\n";
        }
        catch (...)
        {
            std::cout << ":!\n";
        }
    }
}

BitcoinExchange::BitcoinExchange(char *input_file)
{
    std::string buffer_date;
    std::string buffer_price;
    this->input_file = input_file;
    std::ifstream f_csv("data.csv");
    if (!f_csv.is_open())
    {
        std::cout << "Error opening the csv\n";   
        exit(1);
    }
    while (!f_csv.eof() && !f_csv.fail())
    {
        std::getline(f_csv, buffer_date, ',');
        std::getline(f_csv, buffer_price, '\n');
        csv[buffer_date] = atof(buffer_price.c_str());
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &cpy)
{
    this->input_file = cpy.input_file;
    this->csv = cpy.csv;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &cpy)
{
    if (this != &cpy)
    { 
        this->input_file = cpy.input_file;
        this->csv = cpy.csv;
    }
    return *this; 
}

BitcoinExchange::~BitcoinExchange()
{
}

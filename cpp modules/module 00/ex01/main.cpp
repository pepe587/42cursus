#include <iostream>

class   Contact
{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    Contact() {}
    Contact(std::string first_name, std::string last_name, std::string nickname,
            std::string phone_number, std::string darkest_secret)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->nickname = nickname;
        this->phone_number = phone_number;
        this->darkest_secret = darkest_secret;
    }
    bool isEmpty()
    {
        return first_name.empty() || last_name.empty() || nickname.empty()
               || phone_number.empty() || darkest_secret.empty();
    }
    std::string get_first_name(void)
    {
        return this->first_name;
    }
    std::string get_last_name(void)
    {
        return this->last_name;
    }
    std::string get_nickname(void)
    {
        return this->nickname;
    }
    std::string get_phone_number(void)
    {
        return this->first_name;
    }
    std::string get_darkest_secret(void)
    {
        return this->darkest_secret;
    }
};

class   PhoneBook
{
    private:
    Contact array[8];

    public:
    PhoneBook()
    {
        for (int i = 0; i < 8; ++i) {
            array[i] = Contact();
        }
    }

    void    add(void)
    {
        static  int i = 0;
        int         aux;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        aux = 7;
        std::cout << "First name: ";
        std::cin >> first_name;
        std::cout << "\nLast name: ";
        std::cin >> last_name;
        std::cout << "\nNickname: ";
        std::cin >> nickname;
        std::cout << "\nPhone number: ";
        std::cin >> phone_number;
        std::cout << "\nDarkest secret: ";
        std::cin >> darkest_secret;
        if (i < 8)
        {
            this->array[i] = Contact(first_name, last_name, nickname,
                phone_number, darkest_secret);
            i++;
        }
        else
        {
            while (aux > 0)
            {
                array[aux] = array[aux - 1];
                aux--;
            }
            this->array[0] = Contact(first_name, last_name, nickname,
                phone_number, darkest_secret);
        }
    }

    void    print(void)
    {
        int i;
        int x;

        i = 0;
        while (i < 8)
        {
            if (array[i].isEmpty())
                break ;
            std::cout << "Index: " << i + 1 << "\n";
            std::cout << "First name: " << this->array[i].get_first_name();
            std::cout << "\nLast name: " << this->array[i].get_last_name();
            std::cout << "\nNickname: " << this->array[i].get_nickname();
            std::cout << "\nPhone number: " << this->array[i].get_phone_number();
            std::cout << "\nDarkest secret: " << this->array[i].get_darkest_secret() << "\n\n\n\n";
            i++;
        }
        std::cout << "Enter the index:" << std::endl;
        std::cin >> x;
        while (x > i || x < 0)
        {
            std::cout << "Enter a correct index (1-8) or enter 0 to cancel\n";
            std::cout << "Enter the index:" << std::endl;
            std::cin >> x;
        }
        if (x == 0)
                return ;
        std::cout << "Index: " << x << "\n";
        std::cout << "First name: " << this->array[x - 1].get_first_name();
        std::cout << "\nLast name: " << this->array[x - 1].get_last_name();
        std::cout << "\nNickname: " << this->array[x - 1].get_nickname();
        std::cout << "\nPhone number: " << this->array[x - 1].get_phone_number();
        std::cout << "\nDarkest secret: " << this->array[x - 1].get_darkest_secret() << "\n\n\n\n";
        i++;
    }

};

int main(void)
{
    std::string command;
    PhoneBook    persos;   

    std::cin >> command;
    while (command != "EXIT")
    {
        if (command == "ADD")
            persos.add();
        if (command == "SEARCH")
            persos.print();
        std::cin >> command;
    }
    return 0;
}

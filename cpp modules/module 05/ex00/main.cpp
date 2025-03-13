#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  tooHigh(151);
    Bureaucrat  tooLow(0);

    std::cout << "-------------------------------" << std::endl;
    Bureaucrat  Spencer("Spencer", 1);
    Bureaucrat  Scott(0);
    Bureaucrat  Rick("Rick", 151);

    std::cout << std::endl << "-------------------------------" << std::endl;
    Spencer.IncrementGrade();
    Spencer.DecrementGrade();
    std::cout << "-------------------------------" << std::endl;
    std::cout << Spencer << std::endl << std::endl;
    return 0;
}
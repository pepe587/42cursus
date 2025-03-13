#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat bob("Bob", 5);
    Intern  someRandomIntern;
    AForm*   rrf;

    rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");

    if (rrf)
    {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
    }

    delete rrf;
    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

    if (rrf)
    {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
    }   
    delete rrf;
    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");

    if (rrf)
    {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
    }
    delete rrf;
    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("other request", "Bender");

    if (rrf)
    {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
    }

    delete rrf;

    return 0;
}
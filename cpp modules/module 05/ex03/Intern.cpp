#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm *Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string forms[] = {"ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(Intern::*funcs[])(std::string) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
    int i;

    for (i = 0; i < 3 && form_name != forms[i]; i++)
        ;
    if (i == 3 && form_name != forms[2])
    {
        std::cout << "cannot create " + form_name + " form";
        return (NULL);
    }
    return (this->*funcs[i])(target);
}
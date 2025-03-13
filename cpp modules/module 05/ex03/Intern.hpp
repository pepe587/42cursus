#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    AForm *makeForm(std::string form_name, std::string target);
    AForm *createShrubbery(std::string target);
    AForm *createRobotomy(std::string target);
    AForm *createPresidential(std::string target);
};

#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string __target) : AForm("Presidential Pardon", 5, 25), target(__target)
{}
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 5, 25), target("Default target")
{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy)
{
	this->target = cpy.target;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSignature() || executor.getGrade() > this->getminGradeToExecute())
		return false;
    std::cout << target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return true;
}
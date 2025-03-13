#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string __target) : AForm("Robotomy", 72, 45), target(__target)
{}
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("Default target")
{}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy)
{
	this->target = cpy.target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

bool RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSignature() || executor.getGrade() >  this->getminGradeToExecute())
		return false;
    if (rand() % 2 == 0)
        std::cout << target + " has been robotomized" << std::endl;
    else
    {
        std::cout << "robotomy failed" << std::endl;
    	return false;
    }
    return true;
}
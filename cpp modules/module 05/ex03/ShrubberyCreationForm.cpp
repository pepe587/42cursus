#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string __target) : AForm("Shrubbery", 145, 137), target(__target)
{}
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("Default target")
{}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy)
{
	this->target = cpy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

bool ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSignature() || executor.getGrade() >  this->getminGradeToExecute())
		return false;
    std::ofstream file((target + "_shrubbery").c_str(), std::ios::app);
    if (file.is_open())
    {
        file << "        ccee88oo\n"
        "              C8O8O8Q8PoOb o8oo\n"
        "           dOB69QO8PdUOpugoO9bD\n"
        "          CgggbU8OU qOp qOdoUOdcb\n"
        "            6OuU  /p u gcoUodpP\n"
        "              \\\\\\//  /douUP\n"
        "                \\\\\\////\n"
        "                 |||/\\\n"
        "                 |||\\/\n"
        "                 |||||\n"
        "                 |||||\n"
        "                 |||||\n"
        "                 |||||\n"
        "                 |||||\n"
        "                 |||||\n"
        "              ...|||||...\n";
    }
    else
	{
		std::cerr << "Error opening file " << target << " for reading." << std::endl;
		return false;
	}
	return true;
}
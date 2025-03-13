#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::validateGrade(int grade) const
{
    try
    {
        if (grade < 1)
          throw AForm::GradeTooLowException();
        else if (grade > 150)
          throw AForm::GradeTooHighException();
        else
          return grade;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 1;
}

AForm::AForm(std::string name, int gradeexe, int gradesign) : name(name), signature(false), minGradeToSign(gradesign), minGradeToExecute(gradeexe)
{}

AForm::AForm(AForm &cpy) : name(cpy.name), signature(cpy.signature), minGradeToSign(validateGrade(cpy.minGradeToSign)), minGradeToExecute(validateGrade(cpy.minGradeToExecute))
{}

AForm::AForm() : name("Default Name"), signature(false), minGradeToSign(75), minGradeToExecute(10)
{}

AForm::~AForm()
{}

std::ostream &operator<<(std::ostream &os, AForm &f)
{
	os << f.getName() << ", form minGradeToSign " << f.getminGradeToSign()
    << ", form minGradeToExecute " << f.getminGradeToExecute() << std::endl;
	return (os);
}

AForm &AForm::operator=(AForm &other)
{
    signature = other.signature;
    return (*this);
}

void AForm::beSigned(Bureaucrat b)
{
    this->validateGrade(b.getGrade());
    try
    {
        if (b.getGrade() < this->minGradeToSign)
            this->signature = true;
        else
    	    throw AForm::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int AForm::getminGradeToExecute() const
{
	return this->minGradeToExecute;
}

int AForm::getminGradeToSign() const
{
	return this->minGradeToSign;
}


std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSignature() const
{
  return this->signature;
}
#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::validateGrade(int grade)
{
    try
    {
        if (grade < 1)
          throw Form::GradeTooLowException();
        else if (grade > 150)
          throw Form::GradeTooHighException();
        else
          return grade;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 1;
}

Form::Form(std::string name, int gradeexe, int gradesign) : name(name), signature(false), minGradeToSign(gradesign), minGradeToExecute(gradeexe)
{}

Form::Form(Form &cpy) : name(cpy.name), signature(cpy.signature), minGradeToSign(validateGrade(cpy.minGradeToSign)), minGradeToExecute(validateGrade(cpy.minGradeToExecute))
{}

Form::Form() : name("Default Name"), signature(false), minGradeToSign(75), minGradeToExecute(10)
{}



Form::~Form()
{}

std::ostream &operator<<(std::ostream &os, Form &f)
{
	os << f.getName() << ", form minGradeToSign " << f.getminGradeToSign()
    << ", form minGradeToExecute " << f.getminGradeToExecute() << std::endl;
	return (os);
}

Form &Form::operator=(Form &other)
{
    signature = other.signature;
    return (*this);
}

void Form::beSigned(Bureaucrat b)
{
    this->validateGrade(b.getGrade());
    try
    {
        if (b.getGrade() < this->minGradeToSign)
            this->signature = true;
        else
    	    throw Form::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int Form::getminGradeToExecute() const
{
	return this->minGradeToExecute;
}

int Form::getminGradeToSign() const
{
	return this->minGradeToSign;
}


std::string Form::getName() const
{
    return this->name;
}

bool Form::getSignature() const
{
  return this->signature;
}
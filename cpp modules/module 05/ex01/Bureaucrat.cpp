#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat:: Bureaucrat() : name("jorge"), grade(150)
{}
Bureaucrat:: Bureaucrat(std::string name) : name(name)
{}

Bureaucrat:: Bureaucrat(int grade)
{
    try
    {
        if (grade <= 0)
            throw Bureaucrat::GradeTooLowException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = grade;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    try
    {
        if (grade <= 0)
            throw Bureaucrat::GradeTooLowException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = grade;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{}

int Bureaucrat::getGrade()
{
    return this->grade;
}

std::string Bureaucrat::getName()
{
    return this->name;
}

Bureaucrat::Bureaucrat(Bureaucrat &cpy)
{
    if (this != &cpy)
    {
        this->grade = cpy.grade;
    }
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &cpy)
{
    if (this != &cpy)
    {
        this->grade = cpy.grade;
    }
    return *this;
}

void Bureaucrat::IncrementGrade()
{
    try
    {
        if (grade - 1 > 150)
            throw Bureaucrat::GradeTooHighException();
        else if (grade - 1 <= 0)
            throw Bureaucrat::GradeTooLowException();
        else
            grade--;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::DecrementGrade()
{
    try
    {
        if (grade + 1 > 150)
            throw Bureaucrat::GradeTooHighException();
        else if (grade + 1 <= 0)
            throw Bureaucrat::GradeTooLowException();
        else
            grade++;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form &form)
{
     if (form.getSignature())
         std::cout << this->getName() << " signed " << form.getName() << std::endl;
     else if (form.getminGradeToSign() > this->getGrade())
         std::cout << this->getName() << " couldn’t sign " << form.getName() <<
           " because " << this->getName() << "´s grade is lowest than minGradeToSign" << std::endl;
     else if (form.getminGradeToSign() >= this->getGrade())
         form.beSigned(*this);
}
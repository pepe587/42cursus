#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class    Form;

class  Bureaucrat
{
private:
    const std::string name;
    int               grade;
public:
/*       CONSTRUCTORS & DESTRUCTORS        */
    Bureaucrat();
    Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat &cpy);
    ~Bureaucrat();
    
/*       MEMBER FUCTIONS        */
    void signForm(Form &form);
    Bureaucrat &operator=(Bureaucrat &cpy);
    int getGrade();
    std::string getName();
    void IncrementGrade();
    void DecrementGrade();
/*       EXCEPTIONS        */
    class GradeTooHighException;
    class GradeTooLowException;
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &f);

class Bureaucrat::GradeTooHighException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too high\n";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too low\n";
    }
};

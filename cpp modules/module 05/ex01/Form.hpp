#pragma once
#include <iostream>

class  Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                signature;
    const int		    minGradeToSign;
	const int		    minGradeToExecute;
public:
    Form();
	Form(std::string name, int minGradeToSign, int minGradeToExecute);
    Form(Form &cpy);
    ~Form();
/*           GETTERS                */
    int getminGradeToExecute() const;
	int getminGradeToSign() const;
    std::string getName() const;
    bool getSignature() const;
/*           MEMBER FUCTIONS        */
    void beSigned(Bureaucrat b);
    int validateGrade(int grade);
    Form &operator=(Form &cpy);
/*           EXCEPTIONS             */
    class GradeTooHighException;
    class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, Form &f);

class Form::GradeTooHighException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too high\n";
    }
};

class Form::GradeTooLowException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too low\n";
    }
};

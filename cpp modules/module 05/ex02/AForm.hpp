#pragma once
#include <iostream>

class  Bureaucrat;

class AForm
{
private:
    const std::string   name;
    bool                signature;
    const int		    minGradeToSign;
	const int		    minGradeToExecute;
public:
    AForm();
	AForm(std::string name, int minGradeToSign, int minGradeToExecute);
    AForm(AForm &cpy);
    virtual ~AForm();
/*           GETTERS                */
    int getminGradeToExecute() const;
	int getminGradeToSign() const;
    std::string getName() const;
    bool getSignature() const;
/*           MEMBER FUCTIONS        */
    void beSigned(Bureaucrat b);
    int validateGrade(int grade) const;
    virtual bool execute(const Bureaucrat &executor) const = 0;
    AForm &operator=(AForm &cpy);
/*           EXCEPTIONS             */
    class GradeTooHighException;
    class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, AForm &f);

class AForm::GradeTooHighException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too high\n";
    }
};

class AForm::GradeTooLowException : public std::exception
{
    virtual const  char *what() const throw()
    {
        return "Exception catched: Grade too low\n";
    }
};

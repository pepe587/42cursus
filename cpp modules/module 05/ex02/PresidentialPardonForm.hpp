#pragma once
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
  private:
  std::string target;
  public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm &cpy);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm	&operator=(PresidentialPardonForm &cpy);
  bool execute(const Bureaucrat &executor) const;
};
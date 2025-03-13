#pragma once
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
  std::string target;
  public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm &cpy);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm	&operator=(ShrubberyCreationForm &cpy);
  bool execute(const Bureaucrat &executor) const;
};
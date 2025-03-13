#pragma once
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
  private:
  std::string target;
  public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm &cpy);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm	&operator=(RobotomyRequestForm &cpy);
  bool execute(const Bureaucrat &executor) const;
};
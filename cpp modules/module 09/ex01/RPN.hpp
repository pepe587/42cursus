#pragma once
#include <iostream>
#include <stack>
#include <exception>
#include <cstdlib>

class RPN {
private:
    std::stack<int> stack;
    RPN();
public:
    RPN(char *o);
    ~RPN();
	void parseop(std::string ops);
	int	PrintResult();
};


class exc : std::exception
{
	private:
		int type;
	public:
	exc(int n) : type(n) {};
	virtual const char *what() const throw()
	{
		if (type == 0)
			return "Error: Character not supported found";
		else if (type == 1)
			return "Error: More than 10 numbers detected";
		else if (type == 2)
			return "Syntax error";
		else if (type == 3)
			return "Error: You cannot divide by zero";
		else if (type == 4)
			return "Error: Numbers with more than 1 digit are not allowed";
		return "";
	}
};

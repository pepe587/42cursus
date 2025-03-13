#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

bool isoperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

void RPN::parseop(std::string op)
{
	short count = 0;
	short opcount = 0;
	unsigned long cmp;
	if (op[0] == ' ')
		throw exc(2);
    for (size_t i = 0; i < op.size(); ++i)
    {
        if (!isdigit(op[i]) && op[i] != '*' && op[i] != '+'
		&& op[i] != '/' && op[i] != '-' && op[i] != ' ')
			throw exc(0);
    }
	if (isdigit(op[op.size() - 1]) || op[op.size() - 1] == ' ')
		throw exc(2);
	for (size_t i = 0; i < op.size(); ++i)
    {
		while (op[i] == ' ')
			++i;
		if (isoperator(op[i]))
			++opcount;
		cmp = i;
		if (isdigit(op[i]))
			++i;
		if (isdigit(op[i]))
			throw exc(4);
		if (cmp != i)
			count++;
        if (count > 10)
			throw exc(1);
    }
	if (opcount != count - 1)
		throw exc(2);
}

int	RPN::PrintResult()
{
	std::cout << stack.top() << "\n";
	return stack.top();
}

int oper(int n1, int n2, char op)
{
	if (op == '*')
		return n1 * n2;
	else if (op == '/')
	{
		if (n2 == 0)
			throw exc(3);
		return n1 / n2;
	}
	else if (op == '+')
		return n1 + n2;
	else if (op == '-')
		return n1 - n2;
	return 0;
}

RPN::RPN(char *o)
{
    std::string op = o;
	int			tmp;
	int			tmp2;

    try { parseop(op); }
    catch(exc e)
    { std::cerr << e.what() << '\n', exit(1); }
	for (size_t i = 0; i < op.size(); ++i)
	{
		if (isdigit(op[i]))
			stack.push(op[i] - '0');
		if (isoperator(op[i]))
		{
			tmp = stack.top();
			stack.pop();
			tmp2 = stack.top();
			stack.pop();
			try
			{ stack.push(oper(tmp2, tmp, op[i])); }
			catch (exc e)
			{ std::cout << e.what() << "\n", exit(1);}
		}
	}
}
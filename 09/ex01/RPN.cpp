#include "RPN.hpp"

RPN::RPN()
{}
RPN::RPN(const RPN& other)
{
	*this = other;
}
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		st = other.st;
	return *this;
}

RPN::~RPN(){}

bool RPN::valid_exp(std::string exp)
{
	if (exp.empty() || !std::isdigit(exp[0]))
		return false;
	int counter = 0;
	for(size_t i = 0; i < exp.size(); ++i)
	{
		if (exp[i] == ' ' && i + 1 != exp.size() && exp[i + 1] != ' ')
			continue;
		else if (std::isdigit(exp[i]) && i + 1 != exp.size() && exp[i + 1] == ' ')
			counter++;
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if (i + 1 != exp.size() && exp[i + 1] != ' ')
				return false;
			counter--;
		}
		else
			return false;
	}
	return (counter == 1);
}

float RPN::compute(std::string exp)
{
	for(size_t i = 0; i < exp.size(); ++i)
	{
		if (std::isdigit(exp[i]))
			st.push(exp[i] - '0');
		else if (exp[i] == ' ')
			continue;
		else
		{
			float b = st.top();
			st.pop();
			float a = st.top();
			st.pop();
			switch(exp[i])
			{
				case '+':
					st.push(a + b);
					break;
				case '-':
					st.push(a - b);
					break;
				case '*':
					st.push(a * b);
					break;
				case '/':
					if(b == 0)
						throw std::runtime_error("Error:: Division by zero!");
					st.push(a / b);
					break;
			}
		}
	}
	return (st.top());
}
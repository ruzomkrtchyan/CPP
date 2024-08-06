#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		bool valid_exp(std::string exp);
		float compute(std::string exp);

	private:
		std::stack<float> st;
};

#endif
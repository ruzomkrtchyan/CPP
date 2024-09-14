#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>

class Span
{
private:
	unsigned int	N;
	std::list<int> lst;
public:
	Span();
	Span(unsigned int num);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	template <typename T> void fillsp(T begin, T end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
		
	}
	
};


#endif
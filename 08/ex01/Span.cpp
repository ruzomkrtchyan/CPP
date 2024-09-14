#include "Span.hpp"

Span::Span():N(0)
{}

Span::Span(unsigned int num):N(num)
{}
Span::Span(const Span &other)
{
	N = other.N;
}

Span& Span::operator=(const Span &other)
{
	N = other.N;
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int num)
{
	if (lst.size() != N)
		this->lst.push_back(num);
	else
		throw std::out_of_range("No space for storing new element!");
}

int Span::shortestSpan()
{
	if(lst.size() < 2)
		throw std::runtime_error("No span can be found!");
	std::list<int> nlst = lst;
	nlst.sort();
	std::list<int>::iterator it = nlst.begin();
	std::list<int>::iterator next = ++nlst.begin();
	int span = *next - *it;
	while(next != nlst.end())
	{
		if (span > *next - *it)
			span  = *next - *it;
		++next;
		++it;
	}
	return (span);
}

int Span::longestSpan()
{
	if(lst.size() < 2)
		throw std::runtime_error("No span can be found!");
	std::list<int>::iterator maxit = std::max_element(lst.begin(), lst.end());
	std::list<int>::iterator minit = std::min_element(lst.begin(), lst.end());
	return (*maxit - *minit);
}

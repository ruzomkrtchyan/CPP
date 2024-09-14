#include "Span.hpp"
#include <ctime>

int main() 
{
	std::srand(time(0));
	try
	{
		Span span(5);
		span.addNumber(5);
		span.addNumber(78);
		span.addNumber(372);
		span.addNumber(1);
		span.addNumber(3);
		// span.addNumber(75);
		std::cout << "The longest span: " << span.longestSpan() << std::endl;
		std::cout << "The shortest span: " << span.shortestSpan() << std::endl;
		std::list<int> lst;
		lst.push_back(8);
		lst.push_back(7856);
		lst.push_back(3);
		lst.push_back(49);
		lst.push_back(51);
		Span sp1(5);
		sp1.fillsp(lst.begin(), lst.end());
		std::cout << "The longest span: " << sp1.longestSpan() << std::endl;
		std::cout << "The shortest span: " << sp1.shortestSpan() << std::endl;
		Span sp3(10000);
		for (size_t i = 0; i < 10000; i++)
			sp3.addNumber(std::rand());
		std::cout << "The longest span: " << sp3.longestSpan() << std::endl;
		std::cout << "The shortest span: " << sp3.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
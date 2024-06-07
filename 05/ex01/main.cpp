#include "Bureaucrat.hpp"

int main()
{
	// std::cout << mard1 << std::endl;

	try
	{
		Bureaucrat mard1("Mesrop", 150);
		mard1.decrement();
		mard1.increment();
		Bureaucrat mard2("Poxos", 1);
		mard2.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


}
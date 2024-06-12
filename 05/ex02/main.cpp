#include "Bureaucrat.hpp"

int main()
{
	// std::cout << mard1 << std::endl;

	try
	{
		Bureaucrat mard1("Mesrop", 120);
		Form paper("Work", 100, 50);
		paper.beSigned(mard1);
		mard1.signForm(paper);
		std::cout << "meow" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
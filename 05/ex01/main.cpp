#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat mard1("Mesrop", 120);
		Bureaucrat mard2("Poxos", 10);
		Form paper("Work", 100, 50);
		mard2.signForm(paper);
		paper.beSigned(mard1);
		std::cout << "meow" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat mard1("Mesrop", 4);
		Bureaucrat mard2("Karl", 10);
		Bureaucrat mard3("Vagho", 120);
		ShrubberyCreationForm p3("home");
		RobotomyRequestForm p2("Crab");
		PresidentialPardonForm paper("Heheh");

		p3.beSigned(mard3);
		mard3.executeForm(p3);
		p3.execute(mard3);
		p2.beSigned(mard2);
		p2.execute(mard2);
		p2.execute(mard2);
		p2.execute(mard2);
		p2.execute(mard2);
		paper.beSigned(mard1);
		paper.execute(mard1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Intern  someRandomIntern;
	Intern	someRandomIntern2;

	AForm*	rrf;
	AForm*	shf;
	rrf = someRandomIntern.makeForm("robot omy request", "Bender");
	shf = someRandomIntern2.makeForm("presidential pardon", "Jack");

	delete rrf;
	delete shf;
}
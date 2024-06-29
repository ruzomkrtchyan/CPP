#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("def"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string _name, int _grade):name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
	if (other.grade < 1)
		throw GradeTooHighException();
	if (other.grade > 150)
		throw GradeTooLowException();
	grade = other.grade;
}
Bureaucrat& Bureaucrat:: operator=(const Bureaucrat& other)
{
	if (other.grade < 1)
		throw GradeTooHighException();
	if (other.grade > 150)
		throw GradeTooLowException();
	grade = other.grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increment()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is Too Low!";
}
void Bureaucrat::decrement()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &paper)
{
	try
	{
		paper.beSigned(*this);
		if (paper.get_issigned())
			std::cout << "Bureaucrat " << name << " signed " << paper.getname() << " form." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Bureaucrat " << name << " couldn't sign the form " << paper.getname() << " because ";
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getname() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't execute " << form.getname() << std::endl;
		std::cerr << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &person)
{
	os << person.getName() << "," << " bureaucrat grade " << person.getGrade();
	return (os);
}
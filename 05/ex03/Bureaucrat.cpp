#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("def"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string _name, int _grade):name(_name)
{
	grade = _grade;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
	grade = other.grade;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat& Bureaucrat:: operator=(const Bureaucrat& other)
{
	grade = other.grade;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
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
	grade--;
	if (grade < 1)
		throw GradeTooHighException();
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
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &paper)
{
	if (paper.get_issigned())
		std::cout << "Bureaucrat " << name << " signed " << paper.getname() << " form." << std::endl;
	else
	{
		std::cout << "Bureaucrat " << name << " couldn't sign the form " << paper.getname() << " because ";
		std::cout << "the grade is too low!" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (!form.get_issigned() || grade >= form.getexgrade())
		std::cout << name << " couldn't execute " << form.getname() << std::endl;
	else
		std::cout << name << " executed " << form.getname() << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &person)
{
	os << person.getName() << "," << " bureaucrat grade " << person.getGrade();
	return (os);
}
#include "Form.hpp"

Form::Form():name("def"), is_signed(0), grade(1), ex_grade(1)
{
}

Form::Form(const std::string name, const int grade, const int ex_grade):name(name), grade(grade), ex_grade(ex_grade)
{
	is_signed = 0;
	if (grade < 1 || ex_grade < 1)
		throw GradeTooHighException();
	if (grade > 150 || ex_grade > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& other):name(other.name), grade(other.grade), ex_grade(other.ex_grade)
{
	is_signed = other.is_signed;
	if (grade < 1 || ex_grade < 1)
		throw GradeTooHighException();
	if (grade > 150 || ex_grade > 150)
		throw GradeTooLowException();
}
Form& Form::operator=(const Form& other)
{
	(void) other;
	return(*this);
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "The grade is Too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "The grade is Too Low!";
}

const std::string Form::getname() const
{
	return (name);
}

int Form::getgrade() const
{
	return (grade);
}

int Form::getexgrade() const
{
	return(ex_grade);
}

bool Form::get_issigned() const
{
	return (is_signed);
}

void Form::beSigned(Bureaucrat &person)
{
	if (person.getGrade() <= grade)
		is_signed = 1;
}
std::ostream& operator<<(std::ostream &os, const Form &paper)
{
	os << paper.getname() << " form ";
	if (paper.get_issigned())
		os << "is signed, the required grade for signing is " << paper.getgrade() 
			<< "the required grade for execution is "<< paper.getexgrade() << std::endl;
	else
		os << "is not signed, the required grade for signing is " << paper.getgrade() 
			<< "the required grade for execution is "<< paper.getexgrade() << std::endl;
	return (os);
}
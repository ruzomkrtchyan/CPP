#include "AForm.hpp"

AForm::AForm():name("def"), is_signed(0), grade(1), ex_grade(1)
{
}

AForm::AForm(const std::string name, const int grade, const int ex_grade):name(name), grade(grade), ex_grade(ex_grade)
{
	is_signed = 0;
	if (grade < 1 || ex_grade < 1)
		throw GradeTooHighException();
	if (grade > 150 || ex_grade > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm& other):name(other.name), grade(other.grade), ex_grade(other.ex_grade)
{
	is_signed = other.is_signed;
	if (grade < 1 || ex_grade < 1)
		throw GradeTooHighException();
	if (grade > 150 || ex_grade > 150)
		throw GradeTooLowException();
}
AForm& AForm::operator=(const AForm& other)
{
	(void) other;
	return(*this);
}

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "The grade is Too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "The grade is Too Low!";
}

const std::string AForm::getname() const
{
	return (name);
}

int AForm::getgrade() const
{
	return (grade);
}

int AForm::getexgrade() const
{
	return(ex_grade);
}

bool AForm::get_issigned() const
{
	return (is_signed);
}

void AForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() <= grade)
		is_signed = 1;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const AForm &paper)
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
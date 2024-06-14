#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool is_signed;
	const int grade;
	const int ex_grade;
public:
	AForm();
	AForm(const std::string name, const int grade, const int ex_grade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string getname() const;
	int getgrade() const;
	int getexgrade() const;
	bool get_issigned() const;
	void beSigned(class Bureaucrat &person);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm &paper);

#endif
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int grade;
	const int ex_grade;
public:
	Form();
	Form(const std::string name, const int grade, const int ex_grade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string getname() const;
	int getgrade() const;
	int getexgrade() const;
	bool get_issigned() const;
	void beSigned(class Bureaucrat &person);

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

std::ostream& operator<<(std::ostream &os, const Form &paper);

#endif
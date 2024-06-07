#ifndef FORM_HPP
#define FORM_HPP

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int grade;
	const int ex_grade;
public:
	Form();
	Form(const std::string name, const int grade, const int ex_grade)
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
};





#endif
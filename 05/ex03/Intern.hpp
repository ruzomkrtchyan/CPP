#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other); 
	~Intern();

	AForm* makeForm(std::string fname, std::string target);
	AForm* shmake(std::string target);
	AForm* rmake(std::string target);
	AForm* pmake(std::string target);

};


#endif
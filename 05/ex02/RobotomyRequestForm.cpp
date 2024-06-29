#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("def")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!get_issigned() || executor.getGrade() >= getexgrade())
		throw GradeTooLowException();
	static int i;
	if (i % 2 == 0)
	{
		std::cout << "Drdrdrrr" << std::endl;
		std::cout << target << " has been robotomized successfully🤖" << std::endl;
	}
	else
		std::cout << "❌ Robotomy failed ❌" << std::endl;
	i++;
}
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("def")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), target(other.target)
{}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other)
{
    target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!get_issigned() || executor.getGrade() >= getexgrade())
        throw GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

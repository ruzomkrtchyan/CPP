#include "Intern.hpp"

Intern::Intern()
{}


Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{}

AForm* Intern::shmake(std::string target)
{
    std::cout << "Intern creates Shrubbery Creation form" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::rmake(std::string target)
{
    std::cout << "Intern creates Robotomy Request form" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::pmake(std::string target)
{
    std::cout << "Intern creates Presidential Pardon form" << std::endl;
    return new PresidentialPardonForm(target);
}

// enum class f_name{};

AForm* Intern::makeForm(std::string fname, std::string target)
{
    int i = 0;
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*(Intern::*fptr[]) (std::string) = {&Intern::shmake, &Intern::rmake, &Intern::pmake};
    while (i < 3 && fname != forms[i])
        i++;
    if (i == 3)
    {
        std::cout << "Wrong form name" << std::endl;
        exit (0);    
    }
    return (this->*fptr[i])(target);
//    switch (fname)
//    {
//         case : 
//             return new ShrubberyCreationForm(target);
//         case : 
//             return new 
   
//         default:
//             break;
//    }
}
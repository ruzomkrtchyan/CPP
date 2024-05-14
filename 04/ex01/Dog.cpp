#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other):type(other.type)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog:: operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructot called" << std::endl;
}

std::string Dog::getType() const
{
    return(type);
}

void Dog::makeSound() const
{
    std::cout << "Haaf haaaf haaaaf!" << std::endl;
}

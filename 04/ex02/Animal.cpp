#include "Animal.hpp"

Animal::Animal():type("def")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other):type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal:: operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return(type);
}

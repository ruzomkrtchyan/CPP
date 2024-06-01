#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    head = new Brain;
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    type = other.type;
    *(head) = *(other.head);
}

Dog& Dog:: operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        head = new Brain;
        *(head) = *(other.head);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete head;
}

std::string Dog::getType() const
{
    return(type);
}

void Dog::makeSound() const
{
    std::cout << "Haaf haaaf haaaaf!" << std::endl;
}

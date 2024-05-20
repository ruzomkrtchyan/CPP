#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Kendani")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other):type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal:: operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Fufufufu" << std::endl;
}

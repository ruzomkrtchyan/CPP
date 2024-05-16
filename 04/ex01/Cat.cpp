#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    head = new Brain;
}

Cat::Cat(const Cat &other):type(other.type)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *(head) = *(other.head);
}

Cat& Cat:: operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        head = new Brain;
        *(head) = *(other.head);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructot called" << std::endl;
    delete head;
}

std::string Cat::getType() const
{
    return(type);
}

void Cat::makeSound() const
{
    std::cout << "Meoow meooow!" << std::endl;
}
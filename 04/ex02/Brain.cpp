#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain:: operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain:: setIdeas(int i, std::string &newid)
{
    ideas[i] = newid;
}

std::string Brain:: getIdeas(int i)
{
    return(ideas[i]);
}
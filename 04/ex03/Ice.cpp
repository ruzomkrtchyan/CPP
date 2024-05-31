#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{}

Ice::Ice(const Ice& other): AMateria(other)
{}

Ice& Ice:: operator=(const Ice& other)
{
    if(this != &other)
        type = other.type;
    return(*this);
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
    AMateria *obj = new Ice();
    return (obj);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
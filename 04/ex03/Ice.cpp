#include "Ice.hpp"

Ice::Ice():Amateria("ice")
{}

Ice::Ice(const Ice& other): Amateria(other)
{}

Ice& operator=(const Ice& other): Amateria operator=(other)
{}

~Ice()
{}

AMateria* Amateria::clone() const
{
    Amateria *obj = new Ice();
    return (obj);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
#include "Cure.hpp"

Cure::Cure():Amateria("cure")
{}

Cure::Cure(const Cure& other): Amateria(other)
{}

Cure& operator=(const Cure& other): Amateria operator=(other)
{}

~Cure()
{}

AMateria* Amateria::clone() const
{
    Amateria *obj = new Cure();
    return (obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
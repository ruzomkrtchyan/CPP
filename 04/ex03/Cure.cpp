#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{}

Cure::Cure(const Cure& other): AMateria(other)
{}

Cure& Cure:: operator=(const Cure& other)
{
   if(this != &other)
        type = other.type;
    return(*this);
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
    AMateria *obj = new Cure();
    return (obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
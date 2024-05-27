#include "AMateria.hpp"

AMateria::AMateria():type("def")
{}

AMateria::AMateria(std::string const & type):this->type(type)
{}

AMateria::AMateria(const AMateria& other)
{
    type = other.type;
}

AMateria& AMateria:: operator=(const AMateria& other)
{
    if(this != &other)
        type = other.type;
    return(*this);
}

AMateria:: ~AMateria()
{}

std::string const & AMateria::getType() const
{
    return(type);
}

void use(ICharacter& target)
{
    std::cout << "Something in AMateria" << std::endl;
}
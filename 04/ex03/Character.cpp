#include "Character.hpp"

Character::Character():name("def")
{
    for (size_t i = 0; i < 4; i++)
        slot[i] = NULL;
    
}

Character::Character(std::string name):this->name(name)
{
    for (size_t i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character::Character(const Character& other)
{
    name = other.name;
    for (size_t i = 0; i < 4; i++)
    {
        delete slot[i];
        slot[i] = other.slot[i];
    }
}

Character& Character:: operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        for (size_t i = 0; i < 4; i++)
        {
            delete slot[i];
            slot[i] = other.slot[i];
        }
    }
    return(*this);
}

Character:: ~Character()
{
    for (size_t i = 0; i < 4; i++)
        delete slot[i];
}

std::string const & Character::getName()
{
    return(name);
}
        
void Character::equip(AMateria* m)
{
    if (m)
    {
        for (size_t i = 0, i < 4, i++)
        {
            if (!slot[i])
            {
                slot[i] = m;
                return ;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (slot[indx] && indx >= 0 && indx <= 3)
    {
        delete slot[indx];
        slot[indx] = NULL;
    }
}

void use(int idx, ICharacter& target)
{
    if (slot[indx] && indx >= 0 && indx <= 3)
    {
        slot[indx]->use(target);
    }
}
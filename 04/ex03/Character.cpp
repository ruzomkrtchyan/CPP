#include "Character.hpp"

Character::Character():name("def")
{
	for (size_t i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(std::string name):name(name)
{
	for (size_t i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const Character& other)
{
	name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
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
			if (slot[i])
				delete slot[i];
			slot[i] = other.slot[i];
		}
	}
	return(*this);
}

Character:: ~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
		}
	}
}

std::string const & Character::getName() const
{
	return(name);
}

bool Character::inInventory(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i] == m)
			return 1;
	}
	return 0;
}
		
void Character::equip(AMateria* m)
{
	if(m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (!slot[i])
			{
				if (inInventory(m))
					slot[i] = m->clone();
				else 
					slot[i] = m;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && slot[idx])
		slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && slot[idx])
		slot[idx]->use(target);
}
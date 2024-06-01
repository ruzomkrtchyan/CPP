#include "MateriaSource.hpp"

MateriaSource:: MateriaSource():type("def")
{
	for (size_t i = 0; i < 4; i++)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	type = other.type;
	for (size_t i = 0; i < 4; i++)
	{
		delete slot[i];
		slot[i] = other.slot[i];
	}
}

MateriaSource& MateriaSource:: operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		type = other.type;
		for (size_t i = 0; i < 4; i++)
		{
			delete slot[i];
			slot[i] = other.slot[i];
		}
	}
	return(*this);
}

MateriaSource:: ~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i])
			delete slot[i];
	}
}

void MateriaSource:: learnMateria(AMateria* m)
{
	if (m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (!slot[i])
			{
				slot[i] = m;
				return ;
			}
		}
	}
}

AMateria* MateriaSource:: createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i] && type == slot[i]->getType())
		{
			return slot[i]->clone();
		}
	}
	return 0;
}
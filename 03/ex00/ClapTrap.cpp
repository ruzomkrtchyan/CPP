#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):this->name(name)
{
	std::cout << "Init constructor called" << std::endl;
	Hit_p = 10;
	Energy_p = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "Copy consrtuctor called" << std::endl;
	this->name = other.name;
	Hit_p = other.Hit_p;
	Energy_p = other.Energy_p;
	Attack_damage = other.Attack_damage;
}

ClapTrap& ClapTrap:: operator=(ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != other)
	{
		this->name = other.name;
		Hit_p = other.Hit_p;
		Energy_p = other.Energy_p;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
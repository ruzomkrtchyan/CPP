#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Hit_p(0), Energy_p(0)
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

void ClapTrap::attack(const std::string& target)
{
	if (Hit_p && Energy_p)
	{
		std::cout << "ClapTrap " << this->name << "attacks " << target 
		<< ", causing " << Attack_damage << "points of damage!" << std::endl;
		// Hit_p -= Attack_damage;
		Energy_p--;
	}
	std::cout << "You are dead, can't do anything else" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	Attack_damage = amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_p && Energy_p)
	{
		std::cout << "ClapTrap " << this->name << "gets " << amount << "hit points back" << std::endl;
		Hit_p += amount;
		Energy_p--;
	}
	std::cout << "You are dead, can't do anything else" << std::endl;
}
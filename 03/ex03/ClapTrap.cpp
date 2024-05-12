#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("Meow"), Hit_p(10), Energy_p(10), Attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	std::cout << "ClapTrap Init constructor called" << std::endl;
	Hit_p = 10;
	Energy_p = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy consrtuctor called" << std::endl;
	this->name = other.name;
	Hit_p = other.Hit_p;
	Energy_p = other.Energy_p;
	Attack_damage = other.Attack_damage;
}

ClapTrap& ClapTrap:: operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
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
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (Hit_p && Energy_p)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target 
		<< ", causing " << Attack_damage << " points of damage!" << std::endl;
		Energy_p--;
		if (Energy_p > 0)
		{
			std::cout << "Now " << name << " has " << Energy_p << " energy." << std::endl;
			return ;
		}
		std::cout << "No Energy 😰" << std::endl;
	}
	std::cout << "You are dead 🔫 can't do anything else." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_p && Energy_p)
	{
		Hit_p -= amount;
		std::cout << name << " was damaged and lost " << amount << " hit points." << std::endl;
		if (Hit_p > 0)
		{
			std::cout << "Now " << name << " has " << Hit_p << " hit points." << std::endl;
			return ;
		}
		std::cout << "No hit points 🤯" << std::endl;
	}
	std::cout << "You are dead 🔫 can't be done anything else." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_p && Energy_p)
	{
		std::cout << this->name << " gets " << amount << " hit points back" << std::endl;
		Hit_p += amount;
		Energy_p--;
		if (Energy_p > 0)
		{
			std::cout << "Now " << name << " has " << Hit_p << " hit points and " << Energy_p << " energy." << std::endl;
			return ;
		}
		std::cout << "No Energy 😰" << std::endl;
	}
	std::cout << "You are dead 🔫 can't do anything else." << std::endl;
}
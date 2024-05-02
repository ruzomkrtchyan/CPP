#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << "ScavTrap Init constructor called" << std::endl;
    Hit_p = 100;
	Energy_p = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &other)
{
	std::cout << "ScavTrap Copy consrtuctor called" << std::endl;
	this->name = other.name;
	Hit_p = other.Hit_p;
	Energy_p = other.Energy_p;
	Attack_damage = other.Attack_damage;
}

ScavTrap& ScavTrap:: operator=(ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		Hit_p = other.Hit_p;
		Energy_p = other.Energy_p;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_p && Energy_p)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target 
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

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
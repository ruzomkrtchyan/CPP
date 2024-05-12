#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap()
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}
DiamondTrap:: DiamondTrap(std::string _name):ClapTrap(_name + "_clap_name"), name(_name)
{
    std::cout << "DiamondTrap Init constructor called" << std::endl;
    Hit_p = 100;
    Energy_p = 50;
    Attack_damage = 30;
}

DiamondTrap:: DiamondTrap(const DiamondTrap &other):ClapTrap(other),ScavTrap(other),FragTrap(other)
{
    std::cout << "DiamondTrap Copy consrtuctor called" << std::endl;
	this->name = other.name;
	Hit_p = other.Hit_p;
	Energy_p = other.Energy_p;
	Attack_damage = other.Attack_damage;
}
DiamondTrap& DiamondTrap:: operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		Hit_p = other.Hit_p;
		Energy_p = other.Energy_p;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}

DiamondTrap:: ~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}    
void DiamondTrap:: attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "Hey, I am DiamondTrap " << this->name << " derived from " << ClapTrap::name << " 😎" << std::endl;
}
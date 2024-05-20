#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "FragTrap Init constructor called" << std::endl;
	Hit_p = 100;
	Energy_p = 100;
	Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap Copy consrtuctor called" << std::endl;
	this->name = other.name;
	Hit_p = other.Hit_p;
	Energy_p = other.Energy_p;
	Attack_damage = other.Attack_damage;
}

FragTrap& FragTrap:: operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		Hit_p = other.Hit_p;
		Energy_p = other.Energy_p;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " high fives everyone 🙌" << std::endl;
}
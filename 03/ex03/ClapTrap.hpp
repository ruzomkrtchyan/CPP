#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	Hit_p;
	unsigned int	Energy_p;
	unsigned int	Attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	ClapTrap& operator=(ClapTrap &other);
	virtual ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};



#endif
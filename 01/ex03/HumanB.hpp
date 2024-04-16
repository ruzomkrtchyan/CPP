#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon	*wep;
	std::string	name;
	public:
	HumanB(std::string name);
	void	setWeapon(Weapon &wp);
	void	attack();
};

#endif
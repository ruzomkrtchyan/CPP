#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon	*wep;
	std::string	name;
	
	public:
	HumanA(std::string name, Weapon &wp);
	void	attack();
};

#endif
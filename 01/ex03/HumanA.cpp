#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp):name(name)
{
	this->wep = &wp;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << wep->getType() << std::endl;
}
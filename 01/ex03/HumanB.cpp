#include "HumanB.hpp"

HumanB::HumanB(std::string name):name(name)
{

}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << wep->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wp)
{
	wep = &wp;
}
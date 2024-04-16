#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) :type(weapon)
{}

const std::string& Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string new_type)
{
	type = new_type;
}
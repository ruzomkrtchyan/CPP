#include "ScavTrap.hpp"

int main()
{
    ScavTrap robo("Shnik");
    // ScavTrap ankap;

    // ankap.attack("Shnik");
    // ankap.guardGate();
    // ankap.takeDamage(9);
    // ankap.takeDamage(98);
    robo.attack("Odz");
    robo.attack("Hav");
    robo.takeDamage(5);
    robo.takeDamage(3);
    robo.beRepaired(7);
    robo.takeDamage(9);
    robo.attack("Kov");
    robo.beRepaired(5);
    robo.takeDamage(3);
    robo.guardGate();
}
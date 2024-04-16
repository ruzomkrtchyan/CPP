#include "Zombie.hpp"

int	main()
{
	Zombie *meow;
	int	n = 5;

	meow = zombieHorde(n, "Ariel");
	for (int i = 0; i < n; i++)
		meow[i].announce();
	delete []meow;
}
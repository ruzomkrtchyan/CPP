#include "Zombie.hpp"

int	main()
{
	Zombie *meow;

	meow = newZombie("Vrdo");
	meow->announce();
	delete (meow);
	randomChump("Yexo");
}
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zo;

	zo = new Zombie[N];
	for (int i = 0; i < N; i++)
		zo[i] = Zombie(name);
	return (zo);
}
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde()
{
}

ZombieHorde::ZombieHorde(int n)
{
	zombie = new Zombie[n];
	_nb = n;

	for (int i = 0; i < n; i++)
	{
		Zombie	copyzomb("Hordes", Zombie::randomName());
		zombie[i] = copyzomb;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] zombie;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < _nb; i++)
		zombie[i].announce();
}

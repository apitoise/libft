#include "ZombieEvent.hpp"

int		main()
{
	ZombieEvent	red;
	ZombieEvent	blue;
	ZombieEvent	boss;
	Zombie 		*redzomb[5];
	Zombie 		*bluezomb[5];
	Zombie		bigboss("boss", "bigboss");
	Zombie 		*littleboss;
	std::string	type;

	type = "Red";
	red.setZombieType(type);
	type = "Blue";
	blue.setZombieType(type);
	type = "LittleBoss";
	boss.setZombieType(type);
	littleboss = boss.newZombie("LittleBoss");
	littleboss->announce();
	bigboss.announce();
	for (int i = 0; i < 5; i++)
		redzomb[i] = red.randomChump();
	for (int i = 0; i < 5; i++)
		bluezomb[i] = blue.randomChump();
	for (int i = 0; i < 5; i++)
	{
		delete	redzomb[i];
		delete	bluezomb[i];
	}
	return (0);
}
#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
private:

	std::string	_type;

public:

	ZombieEvent();
	~ZombieEvent();

	void	setZombieType(std::string const _type);
	Zombie	*newZombie(std::string const name);
	Zombie	*randomChump();
};

#endif
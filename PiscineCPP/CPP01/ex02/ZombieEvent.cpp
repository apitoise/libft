#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(std::string const type)
{
	this->_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string const name)
{
	Zombie *zombie;

	zombie = new Zombie(this->_type, name);
	return (zombie);
}

Zombie 	*ZombieEvent::randomChump()
{
	Zombie 	*zombie;

	zombie = new Zombie(this->_type, Zombie::randomName());
	zombie->announce();
	return (zombie);
}
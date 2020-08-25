#include "Zombie.hpp"

int	Zombie::_id = 0;

Zombie::Zombie()
{
}

Zombie::Zombie(std::string type, std::string name)
{
	this->_type = type;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> is dead.\n";
}


void			Zombie::announce()
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss ...\n";
}

std::string		Zombie::randomName()
{
	int nb;
	std::string	randomName("");
	std::string alpha("abcdefghijklmnopqrstuvwxyz");

	srand(time(0) + _id++);
	while (randomName.size() < 10)
	{
		nb = rand() % 26;
		randomName += alpha.substr(nb, 1);
	}
	return (randomName);
}
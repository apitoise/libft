#include "Zombie.hpp"

class ZombieHorde
{
private:
	int			_nb;
	Zombie		*zombie;

public:
	ZombieHorde();
	ZombieHorde(int n);
	~ZombieHorde();

	void	announce();
};

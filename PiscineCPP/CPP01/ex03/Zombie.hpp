#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Zombie
{
private:

	std::string	_name;
	std::string	_type;
	static int	_id;

public:
	Zombie();
	Zombie(std::string type, std::string name);
	~Zombie();

	void				announce();
	static std::string	randomName();
};

#endif
#include "repo.class.hpp"

int		main(void)
{
	repo		repo;
	std::string	text;
	bool		stop(false);

	while (!stop)
	{
		std::cout << "Put your command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, text);
		if (text == "ADD")
			repo.addcontact();
		else if (text == "SEARCH")
			repo.searchcontact();
		else if (text == "EXIT")
		{
			stop = true;
			repo.~repo();
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
}
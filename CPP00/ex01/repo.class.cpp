#include "repo.class.hpp"
#include "contact.class.hpp"

repo::repo()
{
	this->id = 0;
}

repo::~repo()
{
}

void	repo::fieldentry()
{
	std::string	text;
	bool		stop(false);

	while (!stop)
	{
		std::cout << "Put your command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, text);
		if (text == "ADD")
			repo::addcontact();
		else if (text == "SEARCH")
			repo::searchcontact();
		else if (text == "EXIT")
		{
			stop = true;
			repo::~repo();
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
}

void	repo::addcontact()
{
	if (this->id >= 8)
		std::cout << "The repository is full !" << std::endl;
	else
	{
		this->contact[this->id].getinfo();
		this->id++;
	}
}

void	repo::searchcontact(void)
{
	int	i(0);
	int	index;

	if (this->id == 0)
		std::cout << "This repository is empty !" << std::endl;
	else
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|  Index   |First Name|Last Name | Nickname |" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		while (i < this->id)
		{
			this->contact[i].displayrepository(i + 1);
			i++;
		}
		index = contact[i].searchcontact(id, this->id);
		contact[index - 1].displayinfo();
	}
}
#include "ClassRepo.hpp"
#include "ClassContact.hpp"

Repo::Repo()
{
	this->id = 0;
}

Repo::~Repo()
{
}

void	Repo::fieldentry()
{
	std::string	text;
	bool		stop(false);

	while (!stop)
	{
		std::cout << "Put your command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, text);
		if (text == "ADD")
			Repo::addcontact();
		else if (text == "SEARCH")
			Repo::searchcontact();
		else if (text == "EXIT")
		{
			stop = true;
			Repo::~Repo();
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
}

void	Repo::addcontact()
{
	if (this->id >= 8)
		std::cout << "The repository is full !" << std::endl;
	else
	{
		this->contact[this->id].getinfo();
		this->id++;
	}
}

void	Repo::searchcontact(void)
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
		index = contact[i].searchcontact(this->id);
		contact[index - 1].displayinfo();
	}
}
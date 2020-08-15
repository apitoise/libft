#include "repo.class.hpp"
#include "contact.class.hpp"

repo::repo()
{
	this->id = 0;
}

repo::~repo()
{
}

void	repo::addcontact()
{
	if (this->id >= 8)
		std::cout << "The repository is full !" << std::endl;
	else
	{
		this->contact[this->id].getinfo(this->id + 1);
		this->id++;
	}
}

void	repo::searchcontact(void)
{
	if (this->id == 0)
		std::cout << "This repository is empty !" << std::endl;
	else
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|  Index   |First Name|Last Name | Nickname |" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		for (int i = 0; i < this->id; i++)
			this->contact[i].searchcontact(i + 1);
	}
}
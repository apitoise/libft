#include "contact.class.hpp"

std::string			contact::nameinfo[11] = {
	"First Name : ",
	"Last Name : ",
	"Nickname : ",
	"Login : ",
	"Postal Address : ",
	"Email Address : ",
	"Phone Number : ",
	"Birthday : ",
	"Favorite Meal : ",
	"Underwear Color : ",
	"Darkest Secret : ",
};

contact::contact() {

	for (int i = Fname; i <= Secret; i++)
		this->information[i] = std::string();

}

contact::~contact() {

}

void	contact::displayinfo(void)
{
	for (int i = Fname; i <= Secret; i++)
		std::cout << contact::nameinfo[i] << this->information[i] << std::endl;
}

void	contact::getinfo(void)
{
	for (int i = Fname; i <= Secret; i++)
	{
		bool	first(true);

		while (!this->information[i].size())
		{
			if (!first)
				std::cout << "Empty entry." << std::endl;
			std::cout << contact::nameinfo[i];
			std::getline(std::cin, this->information[i]);
			first = false;
		}
	};
}

void	contact::displayrepository(int id)
{
	std::cout << "|     " << id << "    ";
	for (int j = Fname; j <= Nname; j++)
	{
		std::cout << "|";
		if (this->information[j].size() == 10)
			std::cout << this->information[j];
		else if (this->information[j].size() > 10)
			std::cout << this->information[j].substr(0, 9) << ".";
		else if (this->information[j].size() < 10)
		{
			std::cout << this->information[j];
			for (int len = this->information[j].size(); len < 10; len++)
				std::cout << " ";
		}
	}
	std::cout << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

int		contact::searchcontact(int id, int nb)
{
	std::string	index;
	bool		first(true);

	while (!index.size() || index.size() > 1 || index < "1" || index > "8")
	{
		if (!first)
			std::cout << "Wrong entry." << std::endl;
		std::cout << "Wich contact ? (write index): ";
		std::getline(std::cin, index);
		first = false;
	}
	if (std::stoi(index) < 1 || std::stoi(index) > nb)
	{
		std::cout << "Wrong index." << std::endl;
		contact::searchcontact(id, nb);
	}
	return (std::stoi(index));
}
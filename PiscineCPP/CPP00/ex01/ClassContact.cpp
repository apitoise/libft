#include "ClassContact.hpp"

std::string			Contact::nameinfo[11] = {
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

Contact::Contact() {

	for (int i = Fname; i <= Secret; i++)
		this->information[i] = std::string();

}

Contact::~Contact() {

}

void	Contact::displayinfo(void)
{
	for (int i = Fname; i <= Secret; i++)
		std::cout << Contact::nameinfo[i] << this->information[i] << std::endl;
}

void	Contact::getinfo(void)
{
	for (int i = Fname; i <= Secret; i++)
	{
		bool	first(true);

		while (!this->information[i].size())
		{
			if (!first)
				std::cout << "Empty entry." << std::endl;
			std::cout << Contact::nameinfo[i];
			std::getline(std::cin, this->information[i]);
			first = false;
		}
	};
}

void	Contact::displayrepository(int id)
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
			std::cout << std::setw(10);
			std::cout << this->information[j];
		}
	}
	std::cout << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

int		Contact::searchcontact(int nb)
{
	std::string	index;
	bool		first(true);

	while (!index.size() || index.size() > 1 || index < "1" || index > "8"
		|| std::stoi(index) < 1 || std::stoi(index) > nb)
	{
		if (!first)
			std::cout << "Wrong entry." << std::endl;
		std::cout << "Wich contact ? (write index): ";
		std::getline(std::cin, index);
		first = false;
	}
	return (std::stoi(index));
}
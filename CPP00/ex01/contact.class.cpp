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

void	contact::getinfo(int id)
{
	for (int i = Fname; i <= Secret; i++)
	{
		std::cout << contact::nameinfo[i];
		std::getline(std::cin, this->information[i]);
	};
}

void	contact::searchcontact(int id)
{
	std::cout << "|     " << id << "    ";
	for (int j = Fname; j <= Nname; j++)
	{
		std::cout << "|";
		if (this->information[j].size() == 0)
			this->information[j] = "  empty   ";
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
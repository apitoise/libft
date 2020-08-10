#include <iostream>
#include "contact.class.hpp"

void	ft_add()
{
	char	*input;

	std::cout << "Put your first name: " << std::endl;
	std::cin >> input;
	contact	input;
	this->firstname = input;
	std::cout << this->firstname << std::endl;
}

void	ft_search()
{
	std::cout << "IT S SEARCH FUNC" << std::endl;
}

void	ft_exit()
{
	std::cout << "IT S EXIT FUNC" << std::endl;
}
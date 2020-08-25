#include "Pony.hpp"

Pony::Pony()
{
	std::cout << "Pony's name: ";
	std::getline(std::cin, Pony::_name);
	std::cout << "Pony's color: ";
	std::getline(std::cin, Pony::_color);
	std::cout << "Pony's height(cm): ";
	std::getline(std::cin, Pony::_height);
	std::cout << "Pony's weight(kg): ";
	std::getline(std::cin, Pony::_weight);
	std::cout << std::endl;
	std::cout << "Hello ! My pony is " << Pony::_color << ". His name is ";
	std::cout << Pony::_name << ". He weighs " << Pony::_weight << "kg for ";
	std::cout << Pony::_height << "cm and I love him so much.\n\n";
}

Pony::~Pony()
{
	std::cout << "OH MY GOD MY PONEY IS DEAD !\n";
}
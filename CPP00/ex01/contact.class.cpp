#include <iostream>
#include "contact.class.hpp"

contact::contact() {

	std::cout << "Constructor called" << std::endl;
}

contact::~contact() {

	std::cout << "Destructor called" << std::endl;
}
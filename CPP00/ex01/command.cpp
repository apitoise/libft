#include <iostream>
#include "contact.class.hpp"

int		parsing(int len)
{
	if (len == 3)
		ft_add();
	if (len == 4)
		ft_exit();
	if (len == 6)
		ft_search();
	return (0);
}

int		check_error(char *str)
{
	if ((ft_strlen(str) == 3 && !ft_strncmp(str, "ADD", 3)) ||
		(ft_strlen(str) == 4 && !ft_strncmp(str, "EXIT", 4)) ||
		(ft_strlen(str) == 6 && !ft_strncmp(str, "SEARCH", 6)))
		return (parsing(ft_strlen(str)));
	else
	{
		std::cout << "Invalid command." << std::endl;
		return (1);
	}
}

void	command(char *text)
{
	std::cout << "Put your command: ";
	std::cin >> text;
	if (check_error(text))
	{
		command(text);
	}
}
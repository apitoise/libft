#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int		main()
{
	int nb;
	std::string	randomName("");
	std::string alpha("abcdefghijklmnopqrstuvwxyz");

	srand(time(NULL));
	while (randomName.size() < 10)
	{
		nb = rand() % 26;
		randomName += alpha.substr(nb, 1);
	}
	std::cout << randomName << std::endl;
}
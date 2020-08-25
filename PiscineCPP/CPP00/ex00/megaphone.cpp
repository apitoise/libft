#include <iostream>

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int		i(0);
		int		j(1);

		while (j < argc)
		{
			while (argv[j][i])
			{
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
					std::cout << char(argv[j][i] - 32);
				else
					std::cout << argv[j][i];
				i++;
			}
			j++;
			i = 0;
		}
		std::cout << std::endl;
	}
	return (0);
}
#include <iostream>

namespace	Foo {

	int		testint = 7;
	char	testchar[] = "Salut c'est un test.";
}

namespace	Bar {

	int		testint = 1;
	char	testchar[] = "Sulat cs'et nu tset.";
}

int		main(int argc, char **argv)
{
	int		testint = 4;
	char	testchar[] = "Rien à voir.";

	std::cout << testint << std::endl << testchar << std::endl << Foo::testint << std::endl << Foo::testchar << std::endl
	<< Bar::testint << std::endl << Bar::testchar << std::endl;
	return (0);
}
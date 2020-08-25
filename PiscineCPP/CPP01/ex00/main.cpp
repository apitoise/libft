#include "Pony.hpp"

void	ponyOnTheStack()
{
	Pony	myPony;

	return;
}

void	ponyOnTheHeap()
{
	Pony	*myPony = new Pony();

	delete myPony;
	return;
}

int		main()
{
	std::cout << "The first pony is on the stack. I'm going to destroy it but the owner doesn't know.\n\n";
	ponyOnTheStack();
	std::cout << std::endl;
	std::cout << "If the pony is dead then it no longer exist. I'm going to do the same to the one on the heap, watch out.\n\n";
	ponyOnTheHeap();
	return (0);
}
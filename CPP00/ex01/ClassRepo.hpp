#ifndef CLASSREPO_CPP
# define CLASSREPO_CPP
# include <iostream>
# include "ClassContact.hpp"

class Repo
{
public:

	int		id;
	Contact	contact[8];
	Repo();
	~Repo();

	void	addcontact();
	void	searchcontact();
	void	fieldentry();
};

#endif
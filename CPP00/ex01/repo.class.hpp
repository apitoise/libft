#ifndef REPO_CLASS_CPP
# define REPO_CLASS_CPP
# include <iostream>
# include "contact.class.hpp"

class repo
{
public:

	int		id;
	contact	contact[8];
	repo();
	~repo();

	void	addcontact();
	void	searchcontact();
	void	fieldentry();
};

#endif
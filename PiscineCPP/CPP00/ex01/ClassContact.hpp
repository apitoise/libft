#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
public:
	std::string			information[11];
	static std::string	nameinfo[11];

	enum info
	{
		Fname = 0,
		Lname,
		Nname,
		Login,
		Address,
		Email,
		Phone,
		Bday,
		Mea,
		Underwear,
		Secret,
	};
	Contact();
	~Contact();

	void	getinfo(void);
	int 	searchcontact(int nb);
	void	displayrepository(int id);
	void	displayinfo(void);
};

#endif
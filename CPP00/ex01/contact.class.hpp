#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <string>

int		main(void);
void	command(void);
void	ft_add(void);
void	ft_exit(void);

class contact
{
public:
	std::string			information[11];
	static std::string			nameinfo[11];

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
	contact();
	~contact();

	void		getinfo(int id);
	void		searchcontact(int id);
};

#endif
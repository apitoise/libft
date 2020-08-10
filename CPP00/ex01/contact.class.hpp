#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

int		main(void);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	command(char *text);
void	ft_add(void);
void	ft_exit(void);
void	ft_search(void);

class contact
{
public:

	int		id;
	char	*firstname;
	char	*lastname;
	char	*nickname;
	char	*login;
	char	*postaladdress;
	char	*email;
	char	*phonenb;
	char	*bday;
	char	*favmeal;
	char	*underwrclr;
	char	*secret;
	contact();
	~contact();
	
};

#endif
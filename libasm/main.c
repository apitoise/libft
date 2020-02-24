extern int	ft_strlen(char *str);
extern char	*ft_strcpy(char *dest, char *src);
extern int	ft_strcmp(char *s1, char *s2);

int		main(void)
{
	char	str[] = "SALUTsdfDSF dsHIUGHF";
	char	src[] = "coucoufJD Flkmfs";
	char *ptr;

	printf("ft_strcmp: %d\n", ft_strcmp(str, src));
	ptr = ft_strcpy(str, src);
	printf("ft_strlen: %d\n", ft_strlen(str));
	printf("str = [%s], ptr = [%s]\n", str, ptr);
	return (0);
}

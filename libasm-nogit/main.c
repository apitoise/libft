extern int	ft_strlen(char *str);
extern char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char	*str;
	char	src[] = "Salut";

	str = ft_strcpy(str, src);
	printf("%d\n", ft_strlen(src));
	printf("%s", str);
	return (0);
}

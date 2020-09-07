#include "../headers/minishell.h"
#include "../libft/libft.h"

void 			printList(t_varlist **lst)
{
	t_varlist	*current;

    if (*lst == NULL)
        return ;
    current = *lst;
    while (current != NULL)
    {
        printf("%s = %s\n", current->name, current->content);
        current = current->next;
    }
    printf("NULL\n");
}

static void		create_list(char *name, char *content, t_varlist **lst)
{
	t_varlist	*current;
	t_varlist	*new;

	new = malloc(sizeof(t_varlist));
	new->name = name;
	new->content = content;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

static int		is_ok(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	else
		return (1);
} 

void			ft_varenv(char **cmd, t_varlist **lst)
{
	int			i;
	int			j;
	char		*name;
	char		*content;


	i = 0;
	while (cmd[0][i] != '=')
	{
		if (!is_ok(cmd[0][i]))
			i++;
		else
			return ;
	}
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while (cmd[0][i] != '=')
	{
		name[i] = cmd[0][i];
		i++;
	}
	name[i] = '\0';
	i += 1;
	content = malloc(sizeof(char) * ft_strlen(cmd[0] + i) + 1);
	j = 0;
	while (cmd[0][i])
	{
		content[j] = cmd[0][i];
		i++;
		j++;
	}
	content[j] = '\0';
	create_list(name, content, lst);
	printList(lst);
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:38:18 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/13 20:15:25 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_list(t_list *alst)
{
	printf("List :\n");
	if (!alst)
	{
		printf("-Empty list\n");
		return ;
	}
	while (alst)
	{
		printf("-Element : %s\n", (char *)alst->content ? (char *)alst->content : "(null)");
		alst = alst->next;
	}
}

void	del_content(void *content)
{
	content ? printf("Content deleted : %s\n", (char*)content) : printf("No content to delete\n");
}

void	function(void *el)
{
	printf("Function applied to %s\n", (char *)(((t_list *)el)->content));
}

void	*dup_el(void *el)
{
	char	*new_cont;
	size_t	i;

	if (!el)
		return (NULL);
	new_cont = malloc((ft_strlen((char *)((t_list *)el)->content) + 1) * sizeof(char));
	i = 0;
	while (((char *)((t_list*)el)->content)[i])
	{
		new_cont[i] = ((char *)((t_list *)el)->content)[i];
		i++;
	}
	new_cont[i] = '\0';
	return (new_cont);
}

int		main(void)
{
	t_list		*lst;
	t_list		*tmp;

	lst = NULL;
	print_list(lst);
	printf("| Last->%s\n", ft_lstlast(lst) ? (char *)(ft_lstlast(lst)->content) : "(null)");
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add front Bonjour---\n");	
	ft_lstadd_front(&lst, ft_lstnew("Bonjour"));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));
	
	printf("\n---Add front NULL---\n");	
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Del one---\n");
	tmp = lst;
	lst = lst->next;
	ft_lstdelone(tmp, del_content);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add front Legumes---\n");	
	ft_lstadd_front(&lst, ft_lstnew("Legumes"));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add front nothing---\n");	
	ft_lstadd_front(&lst, NULL);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add front Test---\n");	
	ft_lstadd_front(&lst, ft_lstnew("Test"));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add back nothing---\n");	
	ft_lstadd_back(&lst, NULL);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add back The end---\n");	
	ft_lstadd_back(&lst, ft_lstnew("The end"));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Del one---\n");
	tmp = lst;
	lst = lst->next;
	ft_lstdelone(tmp, del_content);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Add front Begining---\n");	
	ft_lstadd_front(&lst, ft_lstnew("Begining"));
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Apply function---\n");	
	ft_lstiter(lst, function);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Duplicated lst---\n");	
	tmp = ft_lstmap(lst, dup_el);
	print_list(tmp);
	printf("| Last->%s\n", (char *)(ft_lstlast(tmp)->content));
	printf("| Size->%d\n", ft_lstsize(tmp));
	
	printf("\n---Del Legumes until The End---\n");
	ft_lstclear(&lst->next, del_content);
	print_list(lst);
	printf("| Last->%s\n", (char *)(ft_lstlast(lst)->content));
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Clear list---\n");
	ft_lstclear(&lst, del_content);
	print_list(lst);
	printf("| Last->%s\n", ft_lstlast(lst) ? (char *)(ft_lstlast(lst)->content) : "(null)");
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Apply function---\n");	
	ft_lstiter(lst, function);
	print_list(lst);
	printf("| Last->%s\n", ft_lstlast(lst) ? (char *)(ft_lstlast(lst)->content) : "(null)");
	printf("| Size->%d\n", ft_lstsize(lst));

	printf("\n---Duplicated lst---\n");	
	tmp = ft_lstmap(lst, dup_el);
	print_list(tmp);
	printf("| Last->%s\n", ft_lstlast(tmp) ? (char *)(ft_lstlast(tmp)->content) : "(null)");
	printf("| Size->%d\n", ft_lstsize(tmp));

	printf("\n-----------\n");	
	return (0);
}

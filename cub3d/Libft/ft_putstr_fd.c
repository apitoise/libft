/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:26:51 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/29 15:12:23 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *s)
{
	int	idx;

	idx = 0;
	if (s == NULL)
		return ;
	while (s[idx])
	{
		ft_putchar(s[idx]);
		idx++;
	}
}

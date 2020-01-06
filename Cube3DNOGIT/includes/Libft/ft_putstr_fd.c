/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:26:51 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/06 16:22:26 by apitoise         ###   ########.fr       */
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

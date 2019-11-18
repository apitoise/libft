/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:19:34 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 16:36:01 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		va;
	int			idx;
	t_flags		flags;

	va_start(va, str);
	{
		idx = 0;
		while (str[idx])
		{
			if (str[idx] == '%')
				idx = ft_parsing(va, str, idx, &flags);
			while (str[idx] && str[idx] != '%')
			{
				ft_putchar(str[idx], &flags);
				idx++;
			}
		}
	}
	va_end(va);
	return (flags.ret);
}

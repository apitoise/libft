/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:46:02 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 14:54:29 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../headers/ft_printf.h"

void		ft_putlstr(char *str, int len, t_flags *flags)
{
	while (*str && len > 0)
	{
		ft_putchar(*str, flags);
		len--;
		str++;
	}
}

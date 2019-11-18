/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:17:32 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 16:36:05 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void		init_struct(t_flags	*flags)
{
	int		first;

	if (first != 1)
	{
		first = 1;
		flags->ret = 0;
	}
	flags->flag = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->width = 0;
	flags->precision = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:52:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 14:35:44 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		pf_s(va_list va, int pos, t_flags *flags)
{
	char	*str;

	str = va_arg(va, char *);
	ft_putstr(str);
	return (pos + 1);
}

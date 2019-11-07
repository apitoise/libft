/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/07 17:02:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parsing(va_list va, const char *str, int pos)
{
	t_flags		flags;

	init_struct(&flags);
	pos += 1;
	while (!(is_conv(str, pos)))
		pos = search_flags(str, pos, &flags);
	printf("dash: %d\n", flags.dash);
	printf("zero: %d\n", flags.zero);
	printf("dot: %d\n", flags.dot);
	printf("star: %d\n", flags.star);
	printf("flag: %d\n", flags.flag);
	if (str[pos] == 'c')
		return (pf_c(va, pos, flags));
	if (str[pos] == 'd' || str[pos + 1] == 'i')
		return (pf_id(va, pos, flags));
	if (str[pos] == 'u')
		return (pf_u(va, pos, flags));
	if (str[pos] == 's')
		return (pf_s(va, pos, flags));
	if (str[pos] == 'p')
		return (pf_p(va, pos, flags));
	if (str[pos] == 'x')
		return (pf_x(va, pos, flags));
	if (str[pos] == 'X')
		return (pf_cx(va, pos, flags));
	if (str[pos] == '%')
		return (pf_percent(va, pos, flags));
	else
		return (-1);
}

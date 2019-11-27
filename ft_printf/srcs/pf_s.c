/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:52:08 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/22 15:27:48 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

void	ft_dot_s(char *str, t_flags *flags)
{
	int		idx;

	idx = 0;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	while (str[idx] && flags->precision > 0)
	{
		ft_putchar(str[idx], flags);
		idx++;
		flags->precision--;
	}
}

void	flags_s(char *str, t_flags *flags)
{
	if (flags->dash > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_s(str, flags);
	else
	{
		if (flags->dot > 0 && flags->precision == 0)
			return ;
		else
			ft_putstr(str, flags);
	}
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

char	*null_func(char *str)
{
	char	*tmp;

	if (!(tmp = ft_strdup("(null)")))
		return (NULL);
	str = tmp;
	free(tmp);
	return (str);
}

int		pf_s(char *str, int pos, t_flags *flags)
{
	if (str == NULL)
		str = null_func(str);
	flags->len = ft_strlen(str);
	if (flags->precision > 0)
		flags->len = (flags->len > flags->precision) ? flags->precision
			: flags->len;
	if (flags->dot > 0 && flags->precision == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_s(str, flags);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0)
			return (pos + 1);
		else
			ft_putstr(str, flags);
	}
	return (pos + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:55:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/07 18:26:50 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int		flag;
	int		dash;
	int		zero;
	int		dot;
	int		star;
}					t_flags;

int		ft_parsing(va_list va, const char *str, int pos);
int		ft_printf(const char *str, ...);
int		pf_c(va_list va, int pos, t_flags flags);
int		pf_s(va_list va, int pos, t_flags flags);
int		pf_id(va_list va, int pos, t_flags flags);
int		pf_p(va_list va, int pos, t_flags flags);
int		pf_u(va_list va, int pos, t_flags flags);
int		pf_x(va_list va, int pos, t_flags flags);
int		pf_cx(va_list va, int pos, t_flags flags);
int		pf_percent(va_list va, int pos, t_flags flags);
int		check_error(const char *str, int pos);
int		percent_nb(char *str);
void	init_struct(t_flags *flags);
int		search_flags(const char *str, int pos, t_flags *flags);
int		is_conv(const char *str, int pos);
int		is_flag(const char *str, int pos);

#endif

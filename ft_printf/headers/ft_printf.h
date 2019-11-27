/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:55:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/27 15:04:18 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct	s_flags
{
	int			flag;
	int			dash;
	int			zero;
	int			dot;
	int			star;
	int			width;
	int			precision;
	int			len;
	int			ret;
}				t_flags;

int				ft_parsing(va_list va, const char *str, int pos
				, t_flags *flags);
int				ft_printf(const char *str, ...);
int				pf_c(int c, int pos, t_flags *flags);
int				pf_s(char *str, int pos, t_flags *flags);
int				pf_id(int nbr, int pos, t_flags *flags);
int				pf_p(unsigned long int n, int pos, t_flags *flags);
int				pf_u(int nbr, int pos, t_flags *flags);
int				pf_x(int nbr, int pos, t_flags *flags);
int				pf_cx(int nbr, int pos, t_flags *flags);
int				pf_percent(int pos, t_flags *flags);
void			init_struct(t_flags *flags);
void			init_ret(t_flags *flags);
int				search_flags(va_list va, const char *str, int pos
				, t_flags *flags);
int				is_conv(const char *str, int pos);
int				is_flag(const char *str, int pos);
int				ft_digitflags(const char *str, int pos, t_flags *flags);

#endif

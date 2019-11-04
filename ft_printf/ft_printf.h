/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:55:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/04 17:02:04 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct		s_resultat
{
	char	*res;
	char	*tmp;
	int		tmpidx;
}					t_resultat;

typedef	struct		s_data
{
	char	*str;
	char	conv;
	int		pos;
}					t_data;

char	*ft_parsing(va_list va, t_data data, t_resultat resultat);
int		ft_printf(const char *str, ...);
char	*pf_c(va_list va, t_data data, t_resultat *resultat);
int		check_error(const char *str, int pos);
int		percent_nb(char *str);
char	*ft_tmp(t_data data, t_resultat *resultat);

#endif

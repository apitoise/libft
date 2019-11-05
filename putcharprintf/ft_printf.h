/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:55:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/05 17:28:34 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_parsing(va_list va, const char *str, int pos);
int		ft_printf(const char *str, ...);
int		pf_c(va_list va);
int		pf_s(va_list va);
int		pf_idu(va_list va);
int		check_error(const char *str, int pos);
int		percent_nb(char *str);

#endif

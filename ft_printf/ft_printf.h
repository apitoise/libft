/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:55:13 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/31 12:57:50 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_parsing(char *str, int len, char *res);
int		ft_printf(const char *str, ...);
char	*pf_c(char *str, int len);

#endif

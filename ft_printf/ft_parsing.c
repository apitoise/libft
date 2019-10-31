/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:06 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/31 12:57:25 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parsing(char *str, int len, char *res)
{
	if (str[len + 1] == 'c')
		return (pf_c(res, len));
//	if (str[len + 1] == 'd' || str[len + 1] == 'i')
//		return (pf_id());
//	if (str[len + 1] == 's')
//		return (pf_s());
//	if (str[len + 1] == 'p')
//		return (pf_p());
//	if (str[len + 1] == 'u')
//		return (pf_u());
//	if (str[len + 1] == 'x')
//		return (pf_x());
//	if (str[len + 1] == 'X')
//		return (pf_cx());
	else
		return (NULL);
}

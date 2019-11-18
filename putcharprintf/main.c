/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:47:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/18 16:36:08 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		main(void)
{
	char	str[6] = "Salut";
	ft_printf("Salut %0*----*u, %-c Comment tu vas ?\n", -10, 4, -45, 'B');
	printf("Salut %0*----*u, %-c Comment tu vas ?\n", -10, 4, -45, 'B');
	return (0);
}

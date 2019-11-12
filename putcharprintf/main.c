/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:47:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/12 18:56:41 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	str[6] = "Salut";
	ft_printf("Salut %025cComment tu vas ?\n",'A');
	printf("Salut %025cComment tu vas ?\n",'A');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:47:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/19 18:03:30 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		main(void)
{
	char	*str = "Arthur est vraiment est beau";
	ft_printf("Salut %030%, Comment tu vas ?\n", 58);
	printf("Salut %030%, Comment tu vas ?\n", 58);
	return (0);
}

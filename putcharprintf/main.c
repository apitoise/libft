/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:47:53 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/05 17:32:15 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_printf("Salut %d comment vas-tu %s?%c dfjdjfdhf\n", 6, "Arthur", 'B');
	printf("Salut %X comment vas-tu %s?%c dfjdjfdhf\n", 'X', "Arthur", 'B');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:09:35 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/03 14:09:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_error(char *str)
{
	ft_putstr_fd("Error\n");
	ft_putstr_fd(str);
	ft_putchar('\n');
	return (0);
}
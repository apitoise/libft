/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:49:46 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/08 16:16:07 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_dead(t_philo *philo)
{
	ft_putnbr((int)get_ms_time());
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" is dead.\n");
	philo->dead = 1;
}

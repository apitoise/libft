/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:21:49 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/08 16:04:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_eat(t_philo *philo)
{
	ft_putnbr((int)get_ms_time());
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" is eating.\n");
	usleep(philo->data.eat * 1000);
	if (get_ms_time() > philo->limit)
		ft_dead(philo);
}

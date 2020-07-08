/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:43:21 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/08 16:04:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_sleep(t_philo *philo)
{
	ft_putnbr((int)get_ms_time());
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" is sleeping.\n");
	usleep(philo->data.sleep * 1000);
	if (get_ms_time() > philo->limit)
		ft_dead(philo);
}

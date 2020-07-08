/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:37:23 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/08 16:20:11 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	ft_putnbr((int)get_ms_time());
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" has taken a fork.\n");
	pthread_mutex_unlock(&philo->mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:37:23 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/14 16:15:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_forks(t_philo *philo)
{
	ft_putnbr(get_time() - philo->begin);
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putstr(" has taken a fork.\n");
}

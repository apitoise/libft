/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:27:09 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/16 16:43:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	display_message(int id, char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->write);
	printf("%llu\n", (get_time() - philo[id].begin));
	ft_putchar(' ');
	ft_putnbr(id);
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar('\n');
	pthread_mutex_unlock(&philo->write);
}

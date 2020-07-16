/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:43:21 by apitoise          #+#    #+#             */
/*   Updated: 2020/07/16 16:43:19 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_one.h"

void	ft_sleep(t_philo *philo)
{
	display_message(philo->id, "is sleeping.", philo);
	usleep(philo->data.sleep * 1000);
	if (get_time() > philo->limit)
		ft_dead(philo);
}

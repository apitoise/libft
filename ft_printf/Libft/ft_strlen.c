/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:19:02 by apitoise          #+#    #+#             */
/*   Updated: 2019/11/21 15:20:43 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int compteur;

	compteur = 0;
	if (str == NULL)
		compteur = 6;
	while (str[compteur] != '\0')
		compteur++;
	return (compteur);
}

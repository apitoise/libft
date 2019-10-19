/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:29:01 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/19 16:05:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE=2000
# include <stdlib.h>
# include <unistd.h>

char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif

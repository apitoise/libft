/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:29:01 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/21 18:10:11 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2000
# define MAX_FD 3000
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // a supprimer

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(char *str);

#endif

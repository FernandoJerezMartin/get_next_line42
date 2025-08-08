/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerez-- <fjerez--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:09:55 by fjerez--          #+#    #+#             */
/*   Updated: 2025/08/08 19:34:08 by fjerez--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
int         read_from_fd(int fd, char **general_buffer);
void		ft_strcpy(char *dest, const char *src, int *index);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
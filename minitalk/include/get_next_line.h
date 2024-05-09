/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:24:38 by skassimi          #+#    #+#             */
/*   Updated: 2024/01/10 15:00:06 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *line);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *left_str, const char *buff);
size_t	ft_strlen(const char *s);
char	*ft_get_line(char *str);
char	*ft_get_left_lines(char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:05:52 by marvin            #+#    #+#             */
/*   Updated: 2023/08/12 19:26:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *free_memory(char **save, char **buf);
char *get_output(char *save);
char *read_source(int fd, char *buf, char *save);
size_t ft_strlen(const char *s);
char	*ft_strjoin(char *save, char *buf);
int search_newline(char *ptr);
char	*ft_strdup(char *save, int start);

#endif

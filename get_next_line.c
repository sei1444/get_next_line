/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seono <seono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:05:55 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 16:59:00 by seono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 42

char *free_memory(char *buf, char *save)
{
    free(buf);
    buf = NULL;
    free(save);
    save = NULL;
    return (NULL);
}

char *read_source(int fd, char *buf, char *save, char *output)
{
    ssize_t bytes_read;

    while (1){
        buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = '\0';
        if (bytes_read == -1)
            return (free_memory(buf, save));
        
    }
}

char *get_next_line(int fd)
{
    static char *save;
    char *buf;
    char *output;

    if (buf == NULL)
        reutrn (NULL);
    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return (read_source(fd, buf, save, output));
}

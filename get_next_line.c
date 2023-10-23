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

char *free_memory(char *s1, char *s2)
{
    free(s1);
    s1 = NULL;
    free(s2);
    s2 = NULL;
    return (NULL);
}

char *read_source(int fd, char *buf, char *save, char *output)
{
    ssize_t bytes_read;

    if (search_newline(save))
    {
        output = ft_strjoin(save, NULL, search_newline(save), 0);
        save = ft_strjoin(save, buf, ft_strlen(save)-serch_newline(save), ft_strlen(buf));
        return (output);
    }
    while (1){
        buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buf == NULL)
            reutrn (free_memory(buf, save));
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = '\0';
        if (bytes_read == -1)
            return (free_memory(buf, save));
        if (search_newline(buf))
        {
            output = ft_strjoin(save, buf, search_newline(buf), searchnewline(buf));
            return (output); 
        }
        else
            save = ft_strjoin(save, buf, ft_strlen(save), ft_strlen(buf));
            if (bytes_read == 0)
                return (save);
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *buf;
    char *output;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return (read_source(fd, buf, save, output));
}

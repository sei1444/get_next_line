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

#include "get_next_line.h"

char *free_memory(char **save, char **buf)
{
    // printf("free\n");
    if (save != NULL && *save != NULL)
    {
        free(*save);
        *save = NULL;
    }
    if (buf != NULL && *buf != NULL)
    {
        free(*buf);
        *buf = NULL;
    }
    return (NULL);
}

char *get_output(char *save)
{
    int i;
    int count;
    char *output;
    char *tmp;

    count = search_newline(save);
    if (count == 0)
        return (save);
    output = malloc(sizeof(char) * (count + 1));
    if (output == NULL)
        return (free_memory(&save, NULL));
    // printf("malloc\n");
    i = 0;
    while (i < count)
    {
        output[i] = (save)[i];
        i++;
    }
    output[i] = '\0';
    tmp = ft_strdup(save, count);
    free_memory(&save, NULL);
    save = tmp;
    return (output);
}

char *read_source(int fd, char *buf, char *save)
{
    ssize_t bytes_read;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (free_memory(&save, NULL));
    while (!search_newline(save))
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
            return (free_memory(&save, &buf));
        else if (bytes_read == 0)
        {
            free_memory(NULL, &buf);
            return (get_output(save));
        }
        buf[bytes_read] = '\0';
        save = ft_strjoin(save, buf);
        if (save == NULL)
            return (free_memory(&save, &buf));
    }
    free(buf);
    return (get_output(save));
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *buf;

    buf = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free_memory(&save, NULL));
    return (read_source(fd, buf, save));
}

// #include <fcntl.h>

// int main(void)
// {
//     int fd;
//     char *ptr;

// 	fd = open("file/nl", O_RDWR);
//     for (size_t i = 0; i < 2; i++)
//     {
//         ptr = get_next_line(fd);
//         printf("s:%s", ptr);
//     }
//     return (0);
// }
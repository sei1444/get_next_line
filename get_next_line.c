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

char *free_memory(char *save, char *buf)
{
    free(save);
    save = NULL;
    free(buf);
    return (NULL);
}

char *get_output(char **save)
{
    int i;
    int count;
    char *output;

    count = search_newline(*save);
    if (count == 0)
        return (*save);
    output = malloc(sizeof(char) * (count + 1));
    if (output == NULL)
        return (free_memory(*save, NULL));
    i = 0;
    while (i < count)
    {
        output[i++] = **save;
        (*save)++;
    }
    output[i] = '\0';
    (*save)++;
    return (output);
}

char *read_source(int fd, char *buf, char *save)
{
    ssize_t bytes_read;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (NULL);
    while (!search_newline(save))
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = '\0';
        if (bytes_read == -1)
            return (free_memory(save, buf));
        else if (bytes_read == 0)
            return (save);
        save = ft_strjoin(save, buf);
    }
    free(buf);
    return (get_output(&save));
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *buf;

    buf = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return (read_source(fd, buf, save));
}


// int main(void)
// {
//     char *ptr;
//     ptr = get_next_line(0);
//     while (ptr != NULL)
//     {
//         ptr = get_next_line(0);
//         printf("%s\n", ptr);
//         free(ptr);        
//     }
//     return (0);
// }
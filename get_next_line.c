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

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

char *free_memory(char *ptr)
{
    free(ptr);
    return (NULL);
}

char *get_output(char **save)
{
    int i;
    int count;
    char *output;
    char *free_ptr;
    char *tmp;

    count = search_newline(*save);
    output = malloc(sizeof(char) * (count + 1));
    if (output == NULL)
        return (free_memory(*save));
    i = 0;
    free_ptr = *save;
    while (i < count)
        output[i++] = *(*save)++;
    output[i] = '\0';
    tmp = NULL;
    if (**save != '\0')
        tmp = ft_strdup(*save);
    free(free_ptr);
    *save = tmp;
    if (*output == '\0')
        return (free_memory(output));
    return (output);
}

char *read_source(int fd, char *buf, char **save)
{
    ssize_t bytes_read;
    char *tmp;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (free_memory(*save));
    bytes_read = 1;
    while (ft_strchr(*save, '\n') == NULL && bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(*save);
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        tmp = ft_strjoin(*save, buf);
        free(*save);
        *save = tmp;
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
    {
        free(save);
        return (NULL);
    }
    return (read_source(fd, buf, &save));
}

// #include <fcntl.h>

// int main(void)
// {
//     int fd;
//     char *ptr;

// 	fd = open("file/alternate_line_nl_with_nl", O_RDWR);
// 	// fd = open("file/a", O_RDWR);
//     for (size_t i = 0; i < 5; i++)
//     {
//         ptr = get_next_line(fd);
//         printf("s:%s", ptr);
//         free(ptr);
//     }
//     return (0);
// }

// int main(){
//     static char *save = NULL;
//     save = malloc(sizeof(char) * 15);
//     save[0] = 'a';
//     save[1] = 'a';
//     save[2] = 'a';
//     save[3] = 'a';
//     save[4] = 'a';
//     save[5] = 'a';
//     save[6] = '\n';
//     save[7] = 'b';
//     save[8] = 'b';
//     save[9] = 'b';
//     save[10] = 'b';
//     save[11] = 'b';
//     save[12] = 'b';
//     save[13] = 'b';
//     save[14] = 'b';
//     save[15] = '\0';
//     char *ptr;
//     ptr = get_output(&save);
//     printf("ptr:%s\n", ptr);
//     printf("save:%s\n", save);
//     free(save);
//     return 0;
// }

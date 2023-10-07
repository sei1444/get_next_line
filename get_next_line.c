/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:05:55 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 09:30:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 42

char *get_next_line(int fd)
{
    ssize_t bytes_read;
    char buf[BUFFER_SIZE];

    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read == -1)
        return NULL;
    else
    {
        
    }
    
}

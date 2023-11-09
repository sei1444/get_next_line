/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:05:57 by marvin            #+#    #+#             */
/*   Updated: 2023/08/11 22:05:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    if (s == NULL)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strjoin(char *save, char *buf)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buf) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (save != NULL && save[i] != '\0')
    {
		ptr[i] = save[i];
        i++;
    }
    j = 0;
	while (buf[j] != '\0')
	{
    	ptr[i + j] = buf[j];
        j++;
    }
    ptr[i + j] = '\0';
    free_memory(&save, NULL);
	return (ptr);
}

int search_newline(char *ptr)
{
    int i;

    if (ptr == NULL)
        return (0);
    i = 1;
    while (ptr[i - 1] != '\0')
    {
        if (ptr[i - 1] == '\n')
            return (i);
        i++;
    }
    return (0);
}

char	*ft_strdup(char *save, int start)
{
	int		i;
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(save) - start + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (save[start + i] != '\0')
	{
		ptr[i] = save[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

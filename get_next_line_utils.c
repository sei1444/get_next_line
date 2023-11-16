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

char	*ft_strchr(const char *s, int c)
{
	char	con;
	char	*str;

    if (s == NULL)
        return (NULL);
	con = (char)c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == con)
			return (str);
		str++;
	}
	if (con == '\0')
		return (str);
	return (NULL);
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
    // free(save);
	return (ptr);
}

int search_newline(char *ptr)
{
    int i;

    if (ptr == NULL)
        return (0);
    i = 0;
    while (ptr[i] != '\0')
    {
        if (ptr[i] == '\n')
            return (i + 1);
        i++;
    }
    return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

    
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

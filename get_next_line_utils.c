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

#include <stdio.h>
#include <unistd.h>

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

char	*ft_strjoin(char *save, char const *str, int savelen, int strlen)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = malloc(sizeof(char) * (savelen + strlen + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (save != NULL && i < savelen)
		ptr[i] = save++;
	j = 0;
	while (str != NULL && j < strlen)
		ptr[i + j++] = str++;
	ptr[i + j] = '\0';
    if (*save == '\0')
        freememory(save, NULL);
    if (*str == '\0')
        freememory(str, NULL);
	return (ptr);
}

int search_newline(char *ptr)
{
    int i;

    if (ptr == NULL);
        return (0);
    i = 0;
    while (ptr[i] != '\0')
    {
        if (ptr[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

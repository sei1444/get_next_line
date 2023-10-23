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

char	*ft_strjoin(char *save, char const *str, int savelen, int s2len)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(save) + s2len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (save != NULL && i < savelen)
		ptr[i] = save++;
	j = 0;
	while (str != NULL && j < s2len)
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

    i = 0;
    while (ptr[i] != '\0')
    {
        if (ptr[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

char *search_save(char *save, char *output)
{
    int count;
    int i;
    int savelen;

    savelen = ft_strlen(save);
    count = 0;
	while (save[count] != '\0' && save[count] != '\n')
        count++;
    output = malloc(sizeof(char) * (count + 1));
    if (output == NULL)
        return (NULL);
    i = 0;
    while (i < count)
        output[i++] = *save++;
    output[i] = '\0';
    save++;
    return (output);
}

// int search_buf(char *const buf)
// {
//     int count;
//     int buflen;

//     buflen = ft_strlen(buf);
//     count = 0;
//     while(buf[count] != '\0'){
//         if (buf[count] != '\n')
//             return (count);
//         count++;
//         }
//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seono <seono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:05:55 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 18:28:58 by seono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_memory(char *p1, char *p2)
{
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	return (NULL);
}

char	*get_output(char **save, int count)
{
	int		i;
	char	*output;
	char	*free_ptr;
	char	*tmp;

	output = malloc(sizeof(char) * (count + 1));
	if (output == NULL)
		return (free_memory(*save, NULL));
	i = 0;
	free_ptr = *save;
	while (i < count)
		output[i++] = *(*save)++;
	output[i] = '\0';
	tmp = NULL;
	if (**save != '\0')
	{
		tmp = ft_strdup(*save);
		if (tmp == NULL)
			return (free_memory(free_ptr, output));
	}
	free(free_ptr);
	*save = tmp;
	if (*output == '\0')
		return (free_memory(output, NULL));
	return (output);
}

char	*read_source(int fd, char *buf, char **save)
{
	int		count;
	ssize_t	bytes_read;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_memory(*save, NULL));
	bytes_read = 1;
	while (ft_strchr(*save, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_memory(*save, buf));
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(*save, buf);
		if (tmp == NULL)
			return (free_memory(*save, buf));
		free(*save);
		*save = tmp;
	}
	free(buf);
	count = count_until_newline(*save);
	return (get_output(save, count));
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*buf;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_memory(save, NULL));
	return (read_source(fd, buf, &save));
}

// #include <fcntl.h>

// int main(void)
// {
// 	FILE *outputfile;
//     int fd;
//     char *ptr;

// 	outputfile = fopen("output", "w");
// 	fd = open("test", O_RDWR);
//     for (size_t i = 0; i < 7; i++)
//     {
//         ptr = get_next_line(fd);
//         printf("s:%s", ptr);
// 		// fprintf(outputfile, "%s", ptr);
//         free(ptr);
//     }
// 	printf("\n");
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
//     return (0);
// }

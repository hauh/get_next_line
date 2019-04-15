/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:36:49 by smorty            #+#    #+#             */
/*   Updated: 2019/04/15 23:24:27 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int n;
	size_t i;
	static char *str;

	if (!str)
	{
		buf[BUFF_SIZE] = '\0';
		str = ft_strdup(buf);
	}
	n = BUFF_SIZE;
	while (!ft_strchr(str, 10)) && n >= BUFF_SIZE)
	{
		n = read(fd, buf, BUFF_SIZE);
		buf[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buf);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	*line = ft_strndup(str, i);
	str = ft_strchr(str, 10) + 1;
	return (1);
}

int main(int argc, char **argv)
{
	char *line;
	unsigned int i;
	int fd;

	i = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (i < 10)
		{
			printf("%d\n", get_next_line(fd, &line));
			printf("%s\n", line);
			i++;
		}
	}
	return (0);
}

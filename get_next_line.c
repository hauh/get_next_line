/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:36:49 by smorty            #+#    #+#             */
/*   Updated: 2019/04/16 22:13:35 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static int	find_newline(char *buf)
{
	char *buf0;

	buf0 = buf;
	while (*buf)
	{
		if (*buf == '\n')
			return (buf - buf0);
		buf++;
	}
	return (0);
}

int	gnl_lst(const int fd, char **line, t_str **list)
{
	char	buf[BUFF_SIZE + 1];
	int n;
	int i;

	if (!*list)
	{
		*list = (t_str *)malloc(sizeof(t_str));
		(*list)->s = (char *)malloc(sizeof(char));
		*(*list)->s = '\0';
		(*list)->file = fd;
		(*list)->next = NULL;
	}
	if (fd != (*list)->file)
		return (gnl_lst(fd, line, &(*list)->next));
	while (!find_newline((*list)->s))
	{
		n = read(fd, buf, BUFF_SIZE);
		if (!n)
			break ;
		if (n < 0)
			return (-1);
		buf[n] = '\0';
		(*list)->s = ft_strjoin((*list)->s, buf);
	}
	if (!*((*list)->s))
		return (0);
	i = find_newline((*list)->s);
	if (!i)
		return (0);
	*line = ft_strndup((*list)->s, i);
	(*list)->s = (*list)->s + i;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_str *list = NULL;

	return (gnl_lst(fd, line, &list));
}

int main(int argc, char **argv)
{
	char *line;
	unsigned int i;
	int fd;

	i = 1;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			printf("main:%d\n", i = get_next_line(fd, &line));
			if (i)
				printf("main:%s\n", line);
		}
	}
	return (0);
}

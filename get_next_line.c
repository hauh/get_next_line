/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:36:49 by smorty            #+#    #+#             */
/*   Updated: 2019/04/17 23:11:13 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_newline(char *s)
{
	char *s0;

	if (s)
	{
		s0 = s;
		while (*s)
		{
			if (*s == '\n')
				return (s - s0 + 1);
			s++;
		}
	}
	return (0);
}

static t_file	*create_list(int fd)
{
	t_file *list;

	list = (t_file *)malloc(sizeof(t_file));
	list->tail = (char *)malloc(sizeof(char) * BUFF_SIZE);
	*list->tail = '\0';
	list->file = fd;
	list->next = NULL;
	return (list);
}

static int		gnl_list(int fd, char **line, t_file **list)
{
	char	buf[BUFF_SIZE + 1];
	char	*clear;
	char	*s;
	int		n;

	if (!*list)
		*list = create_list(fd);
	if (fd != (*list)->file)
		return (gnl_list(fd, line, &(*list)->next));
	s = *(*list)->tail ? ft_strdup((*list)->tail) : ft_strnew(0);
	while (!find_newline(s))
	{
		n = read(fd, buf, BUFF_SIZE);
		if (!n)
			break ;
		if (n < 0)
			return (-1);
		buf[n] = '\0';
		clear = s;
		s = ft_strjoin(s, buf);
		free(clear);
	}
	n = find_newline(s);
	if (!n)
	{
		if (!ft_strlen(s))
		{
			free(s);
			return (0);
		}
		*line = ft_strdup(s);
		if (*(*list)->tail)
			*(*list)->tail = '\0';
	}
	else
	{
		*line = ft_strndup(s, n - 1);
		(*list)->tail = ft_strcpy((*list)->tail, s + n);
	}
	free(s);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file *list = NULL;

	return (gnl_list(fd, line, &list));
}

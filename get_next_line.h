/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:53:26 by smorty            #+#    #+#             */
/*   Updated: 2019/04/16 21:44:51 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 2

typedef struct	s_str
{
	char	*s;
	int		file;
	struct s_str	*next;
}				t_str;

int				get_next_line(const int fd, char **line);
int				gnl_lst(const int fd, char **line, t_str **list);

#endif

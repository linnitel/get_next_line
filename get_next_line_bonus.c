/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisabel <tisabel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:41:23 by tisabel           #+#    #+#             */
/*   Updated: 2020/07/21 05:20:13 by tisabel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Frees the pointers.
*/

int			ft_clean(char **ptr1)
{
	free(*ptr1);
	*ptr1 = NULL;
	ptr1 = NULL;
	return (-1);
}

/*
** Rewrites the static variable's content.
*/

static int	ft_rewrite_tail(char **tail, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str)
		return (-1);
	if (!(*tail))
	{
		*tail = ft_strdup(str);
		return (1);
	}
	if (!(temp = ft_strdup(str)))
		return (ft_clean(tail));
	ft_clean(tail);
	if (!(*tail = ft_strdup(temp)))
		return (ft_clean(&temp));
	ft_clean(&temp);
	return (1);
}

/*
** Reads the text from file and processes it to line and tail.
*/

static int	ft_read_text(char **tail, char **line, int fd)
{
	ssize_t read_num;
	char	*buf;
	char	*ptr_tail;

	buf = NULL;
	if (!(buf = (char*)(malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((read_num = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_num] = '\0';
		if ((ptr_tail = ft_strchr(buf, '\n')))
		{
			ptr_tail[0] = '\0';
			if (!(*line = ft_strjoin(*line, buf)))
				return (ft_clean(&buf));
			free(buf);
			return (ft_rewrite_tail(tail, ptr_tail + 1));
		}
		else if (!(*line = ft_strjoin(*line, buf)))
			return (ft_clean(&buf));
	}
	if (read_num <= 0)
		free(buf);
	return (0);
}

/*
** Operates with remaining read part of the buffer and processes it to line.
** Launches the reading from file if all the string tail remaining
** in memory was printed.
*/

int			get_next_line(int fd, char **line)
{
	static char	*tail[12000];
	char		*ptr_tail;

	ptr_tail = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) == -1 || !(*line = ft_strdup("")))
		return (-1);
	if (tail[fd])
	{
		if ((ptr_tail = ft_strchr(tail[fd], '\n')))
		{
			ptr_tail[0] = '\0';
			if (!(*line = ft_strdup(tail[fd])))
				return (ft_clean(&(tail[fd])));
			return (ft_rewrite_tail(&(tail[fd]), ptr_tail + 1));
		}
		else if (!(*line = ft_strdup(tail[fd])))
			return (ft_clean(&(tail[fd])));
		ft_clean(&(tail[fd]));
	}
	if (!(tail[fd] = ft_strdup("")))
		return (-1);
	return (ft_read_text(&(tail[fd]), line, fd));
}

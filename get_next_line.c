/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisabel <tisabel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:41:23 by tisabel           #+#    #+#             */
/*   Updated: 2020/07/17 16:49:51 by tisabel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	new = malloc((size * count));
	if (new == NULL)
		return (NULL);
	while (i < count * size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

/*
** Frees the pointers. if i = 1, frees one pointer,
** if i = 2, frees two pointers.
*/

static int	ft_clean(char **ptr1, char **ptr2, short i)
{
	if (i < 0 || i > 2 || !(*ptr1))
		return (-1);
	free(*ptr1);
	*ptr1 = NULL;
	ptr1 = NULL;
	if (i == 2)
	{
		if (!(*ptr2))
			return (-1);
		free(*ptr2);
		*ptr2 = NULL;
		ptr2 = NULL;
	}
	return (1);
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
		*tail = ft_strndup(str, 0);
		return (1);
	}
	if (!(temp = ft_strndup(str, 0)) || ft_clean(tail, NULL, 1) == -1
		|| !(*tail = ft_strnjoin(*tail, temp, 0))
		|| ft_clean(&temp, NULL, 1) == -1)
		return (-1);
	return (1);
}

/*
** Reads the text from file and processes it to line and tail.
*/

static int	ft_read_text(char **tail, char **line, int fd)
{
	ssize_t read_num;
	char	*buf;
	int		n;

	if (!(buf = (char*)(ft_calloc(sizeof(char),BUFFER_SIZE + 1))))
		return (-1);
	while ((read_num = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		n = ft_strfind(buf, '\n');
		if (!(*line = ft_strnjoin(*line, buf, n)))
			return (-1);
		if (n != 0)
		{
			if (n == (int)ft_strlen(buf))
				return (ft_clean(&buf, NULL, 1));
			if (!(*tail = ft_strndup(ft_strchr(buf, '\n') + 1, 0)))
				return (ft_clean(&buf, NULL, 1));
			return (ft_clean(&buf, NULL, 1));
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*tail;
	int			result;
	int			n;

	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) == -1 || !(*line = ft_strndup("", 0)))
		return (-1);
	n = ft_strfind(tail, '\n');
	if (tail)
	{
		if (!(*line = ft_strnjoin(*line, tail, n)))
			return (-1);
		if ((n != (int)ft_strlen(tail) && n != 0) || (n == 1 && strlen(tail) == 1))
		{
			return ((ft_rewrite_tail(&tail, ft_strchr(tail, '\n') + 1))
					== -1 ? -1 : 1);
		}
		if (ft_clean(&tail, NULL, 1) == -1)
			return (-1);
	}
	if ((result = ft_read_text(&tail, line, fd)) == -1)
		return (-1);
	if (!tail && result == 0)
		return (0);
	return (1);
}

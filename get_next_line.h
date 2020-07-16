/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisabel <tisabel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 22:50:33 by tisabel           #+#    #+#             */
/*   Updated: 2020/07/16 02:05:22 by tisabel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int			get_next_line(int fd, char **line);
int			ft_strfind(const char *s, int c);
char		*ft_strnjoin(char const *s1, char const *s2, int n);
size_t		ft_strlen(const char *s);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strchr(const char *s, int c);

#endif

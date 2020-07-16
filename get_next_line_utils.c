/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisabel <tisabel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 22:50:07 by tisabel           #+#    #+#             */
/*   Updated: 2020/07/14 16:23:02 by tisabel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strfind(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (c != '\0')
		return (0);
	else
		return (i + 1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (c != 0)
		return (NULL);
	else
		return ((char*)&s[i]);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*joint_str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = (0 < (size_t)n) ? n - 1 : ft_strlen(s2);
	joint_str = (char*)malloc(sizeof(char) * (len_s1
		+ len_s2 + 1));
	if (!joint_str)
		return (0);
	while (i < len_s1)
	{
		joint_str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
		joint_str[i++] = s2[j++];
	joint_str[i] = '\0';
	return (joint_str);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*copy;
	size_t	i;

	length = n;
	i = 0;
	if (n == 0)
		length = ft_strlen(s1);
	copy = (char *)malloc(length + 1);
	if (!copy)
		return (NULL);
	while (i < length || s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	if (n > ft_strlen(s1))
		while (i < n)
		{
			copy[i] = '\0';
			i++;
		}
	copy[i] = '\0';
	return (copy);
}

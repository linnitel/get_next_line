/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisabel <tisabel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 22:50:07 by tisabel           #+#    #+#             */
/*   Updated: 2020/07/21 05:08:30 by tisabel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	unsigned int	length;
	unsigned int	i;
	char			*copy;

	i = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	copy = (char *)malloc(length + 1);
	if (!copy)
		return (NULL);
	while (i < length)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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

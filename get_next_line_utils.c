/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:44:24 by eberkowi          #+#    #+#             */
/*   Updated: 2024/05/15 14:27:12 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;
	size_t	s_length;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if ((size_t)start > s_length)
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if ((s_length - (size_t)start) < len)
		len = s_length - (size_t)start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (len-- > 0)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_string;
	size_t		new_length;
	int			i;

	if (!s1 || !s2)
		return (NULL);
	new_length = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(new_length * sizeof(char) + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		new_string[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new_string[i++] = *s2;
		s2++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

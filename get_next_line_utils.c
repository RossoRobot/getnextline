/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:03:55 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/10 19:20:11 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	size_t	length;
	char	*dest;

	length = ft_strlen(s);
	dest = (char *)malloc(length + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, length + 1);
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	char	c1;

	c1 = (unsigned char)c;
	while (*s)
	{
		if (*s == c1)
			return ((char *)s);
		s++;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	length;

	length = (ft_strlen(s1) + ft_strlen(s2));
	newstr = (char *)malloc(sizeof(char) * (length + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

int	ft_getbufferlength(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	return (i);
}
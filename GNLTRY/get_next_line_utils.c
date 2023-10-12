/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:10 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/12 18:42:10 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	size_t	length;
	char	*dest;
	size_t	i;

	length = ft_strlen(s);
	dest = (char *)malloc(length + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	length;

	if (!s1)
		return (ft_strdup(s2));
	length = (ft_strlen(s1) + ft_strlen(s2));
	newstr = (char *)malloc(sizeof(char) * (length + 1));
	if (!newstr)
		return (ft_free(s2), NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	ft_free(s1);
	return (newstr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

void	ft_free(char *s)
{
	if (s == NULL)
		return ;
	free(s);
	s = NULL;
}

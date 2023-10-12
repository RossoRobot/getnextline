/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:42 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/12 16:54:38 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	checkfornewline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_readline(int fd, char *buffer, char *remainder)
{	
	int		bytes;
	
	if (!remainder)
	{
		remainder = ft_strdup("");
		if (!remainder)
			return(0);
	}
	bytes = 1;
	while(bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break;
		if (bytes == -1)
			return (0);
		buffer[bytes] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return(0);
		if (checkfornewline(buffer) == 1)
			break;
	}
	return (remainder);
}

static char	*ft_trimnextline(char *remainder)
{
	size_t		i;
	size_t		j;
	char	*nextline;

	i = 0;
	j = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
	{
		i++;
	}
	if (remainder[i] == '\n')
		i++;
	nextline = (char *)malloc(sizeof(char) * (i + 1));
	if (!nextline)
		return (NULL);
	while (j < i)
	{
		nextline[j] = remainder[j];
		j++;
	}
	nextline[j] = '\0';
	return (nextline);
}

static char	*ft_extract(char *remainder)
{
	size_t		i;
	size_t	length;
	char	*temp;
	
	i = 0;
	length = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
	{
		i++;
	}
	if(remainder[i] == '\n')
		i++;
	length = (ft_strlen(remainder) - i);
	temp = ft_substr(remainder, i, length);
	free(remainder);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remainder;
	char		*nextline;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	remainder = ft_readline(fd, buffer, remainder);
	free(buffer);
	if (!remainder || !remainder[0])
    {
        free(remainder);
        return (0);
    }
	nextline = ft_trimnextline(remainder);
	remainder = ft_extract(remainder);
	return (nextline);
}

// int	main()
// {
// 	int fd;
// 	int i = 0;
// 	char	*str;

// 	str = "Hallo";
// 	fd = open("file.txt", O_RDONLY);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break;
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
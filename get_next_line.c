/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:54:20 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/10 19:36:07 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *remainder, char *buffer)
{
	int		bytes;
	int		i;
	int		j;
	static char	*temp;
	char	*newline;
	
	bytes = 1;
	i = 0;
	j = 0;
	temp = ft_strdup("");
	newline = NULL;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n') == 0)
		{
			temp = ft_strjoin(temp, buffer);
		}
		else
		{
			newline = (char *)malloc(sizeof(char) * ((ft_strlen(temp) + ft_getbufferlength(buffer)) + 1));
			while(temp[i])
			{
				newline[i] = temp[i];
				i++;
			}
			while(buffer[j])
			{
				newline[i + j] = buffer[j];
				if (buffer[j] == '\n')
				{
					newline[i + j] = '\n';
					j++;
					free(temp);
					break;
				}
				j++;
			}
			break;
		}
	}
	
	newline[i + j] = '\0';
	return (newline);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char 	*remainder;
	char			*newline;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newline = ft_readline(fd, remainder, buffer);
	free(buffer);
	return (newline);
}

int main()
{
	int fd = open( "file.txt" , O_RDONLY);
	printf("nextline: %s", get_next_line(fd));
	printf("nextline: %s", get_next_line(fd));
	printf("nextline: %s", get_next_line(fd));
	close(fd);
	return (0);
}
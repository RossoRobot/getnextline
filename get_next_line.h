/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:58:39 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/10 19:39:38 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int 	ft_getbufferlength(char *buffer);



#endif
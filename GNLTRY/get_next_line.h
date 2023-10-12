/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:56 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/12 18:41:53 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	    *ft_strdup(char *s);
char	    *ft_strjoin(char *s1, char *s2);
size_t	    ft_strlen(char *str);
char	    *ft_substr(char *s, size_t start, size_t len);
void    	ft_free(char *s);
char	    *get_next_line(int fd);

#endif
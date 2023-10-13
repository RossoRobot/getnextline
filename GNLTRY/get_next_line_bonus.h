/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolgger <mvolgger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:09:01 by mvolgger          #+#    #+#             */
/*   Updated: 2023/10/13 16:05:49 by mvolgger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *str);
char		*ft_substr(char *s, size_t start, size_t len);
void		ft_free(char *s);
char		*get_next_line(int fd);

#endif
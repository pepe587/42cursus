/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:32:30 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/07/16 17:17:11 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

unsigned long	ft_strlen(const char *str);
char			*get_next_line(int fd);
char			*ft_substr(char *str, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*update(char *stack, int lenline);
char			*ft_strchr(const char *str, int c);

#endif
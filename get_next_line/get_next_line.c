/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:17 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/07/16 17:18:08 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_strjoin_and_free(char *stack, char *temp)
{
	if (!stack)
	{
		stack = malloc(1);
		if (!stack)
			return (NULL);
		stack[0] = '\0';
	}
	if (!stack)
		return (NULL);
	return (ft_strjoin(stack, temp));
}

static char	*gline(char *stack)
{
	int			i;
	char		*line;
	int			z;

	if (!stack)
		return (NULL);
	z = 0;
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (i > 0)
	{
		line[z] = stack[z];
		i--;
		z++;
	}
	line[z] = '\0';
	return (line);
}

int	ft_free(char *str)
{
	free(str);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	int			readbytes;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (readbytes > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		readbytes = read(fd, temp, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(stack), free(temp), stack = NULL, NULL);
		temp[readbytes] = '\0';
		if (readbytes > 0)
			stack = ft_strjoin_and_free(stack, temp);
		if (!stack)
			return (free(temp), NULL);
		if (ft_free(temp) == 1 && ft_strchr(stack, 10))
			break ;
	}
	return (line = gline(stack), stack = update(stack, ft_strlen(line)), line);
}

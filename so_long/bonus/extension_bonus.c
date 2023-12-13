/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:52:14 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 22:14:59 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b' || str[i - 3] != '.')
		return (ft_printf("Error:\nIncorrect extension,"
				" insert a .ber file"), 0);
	return (1);
}

void	ft_free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**mallocmatrix(char **array)
{
	int		y;
	int		x;
	char	**ret;

	x = 0;
	y = 0;
	while (array[y])
		y++;
	ret = malloc((y + 1) * sizeof(char **));
	y = 0;
	while (array[y])
	{
		ret[y] = malloc(ft_strlen(array[y]) + 1);
		y++;
	}
	return (ret);
}

char	**cpymatrix(char **array)
{
	char	**ret;
	int		y;
	int		x;

	x = 0;
	y = 0;
	ret = mallocmatrix(array);
	while (array[y])
	{
		while (array[y][x])
		{
			ret[y][x] = array[y][x];
			x++;
		}
		ret[y][x] = '\0';
		x = 0;
		y++;
	}
	ret[y] = NULL;
	return (ret);
}

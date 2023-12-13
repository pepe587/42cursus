/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handerrors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:42:07 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 22:10:51 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../so_long.h"

int	check_map_walls(char **map, t_maplen coords)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[0][x] != '\0')
	{
		if (map[0][x] != 49)
			return (0);
		x++;
	}
	x = 0;
	while (map[coords.y - 1][x] != '\0')
	{
		if (map[coords.y - 1][x] != 49)
			return (0);
		x++;
	}
	while (y < coords.y)
	{
		if (map[y][0] != 49 || map[y][coords.x - 1] != 49)
			return (0);
		y++;
	}
	return (1);
}

int	check_map_rectangular(char **map, t_maplen coords)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	if (coords.x == coords.y)
		return (0);
	while (y < coords.y)
	{
		while (map[y][x])
			x++;
		if (x != coords.x)
			return (0);
		x = 0;
		y++;
	}
	return (1);
}

int	check_map_objs(char **map, t_maplen coords)
{
	int			y;
	t_objects	objects;

	y = 0;
	objects.e = 0;
	objects.c = 0;
	objects.p = 0;
	coords.x = 0;
	while (y++ < coords.y - 1)
	{
		while (map[y][coords.x++])
		{
			if (map[y][coords.x] == 'C')
				objects.c++;
			if (map[y][coords.x] == 'P')
				objects.p++;
			if (map[y][coords.x] == 'E')
				objects.e++;
		}
		coords.x = 0;
	}
	if (objects.c >= 1 && objects.p == 1 && objects.e == 1)
		return (1);
	return (0);
}

int	ft_check_solvable(t_tools *tools, int x, int y, int *trues)
{
	char			pos;

	pos = tools->m_map[y][x];
	if (pos != '1' && pos != 'T' && pos != 'Z')
	{
		if (pos == 'E')
			*trues = 1;
		tools->m_map[y][x] = 'T';
		if (x + 1 < tools->proportions.x)
			ft_check_solvable(tools, x + 1, y, trues);
		if (x - 1 >= 0)
			ft_check_solvable(tools, x - 1, y, trues);
		if (y + 1 < tools->proportions.y)
			ft_check_solvable(tools, x, y + 1, trues);
		if (y - 1 >= 0)
			ft_check_solvable(tools, x, y - 1, trues);
	}
	return (*trues);
}

int	check_map(char **map, t_maplen coords, t_tools *tools)
{
	int	errors;
	int	check;

	check = 0;
	errors = 0;
	tools->proportions = coords;
	if (check_map_rectangular(map, coords) == 0)
	{
		ft_printf("Error:\nThe map is not rectangular\n");
		errors++;
	}
	if (check_map_objs(map, coords) == 0)
		return (ft_printf("%s", "Error:\nError with the objects\n"), 0);
	check = ft_check_solvable(tools, tools->coords_char.x,
			tools->coords_char.y, &check);
	if (check == 0)
		return (ft_printf("%s", "Error:\nThe map cannot be resolved\n"), 0);
	if (check_map_walls(tools->m_map, tools->proportions) == 0)
	{
		errors++;
		ft_printf("Error:\nThe map is not closed\n");
	}
	if (errors >= 1)
		return (0);
	return (check_collecs(tools));
}

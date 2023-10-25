/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:11:12 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/10/09 20:39:22 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hand_collec(t_tools *tools)
{
	int		x;
	int		y;
	char	**map;

	x = tools->coords_char.x;
	y = tools->coords_char.y;
	map = tools->map;
	if (map[y][x] == 'C')
	{
		mlx_image_to_window(tools->window, tools->floor, x * 64, y * 64);
		mlx_image_to_window(tools->window, tools->main_character,
			(x * 64) + 13, y * 64);
	}
	if (map[y][x] == 'E')
		mlx_close_window(tools->window);		
}

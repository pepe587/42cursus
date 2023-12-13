/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:59:51 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/07 12:28:19 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_enemies(t_tools *tools)
{
	char			**map;
	int				x;
	int				y;
	mlx_texture_t	*text;

	text = mlx_load_png("Textures/zubat.png");
	tools->zubat = mlx_texture_to_image(tools->window, text);
	map = tools->map;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'Z')
				mlx_image_to_window(tools->window, tools->zubat,
					x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(text);
}

void	hand_enemies(t_tools *tools)
{
	char			**map;

	map = tools->map;
	if (map[tools->coords_char.y][tools->coords_char.x] == 'Z')
		tools->dead = true;
}

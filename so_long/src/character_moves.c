/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:46:53 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/07 13:27:53 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../so_long.h"

void	choose_png(t_tools *tools, enum keys button)
{
	mlx_texture_t	*text;

	mlx_delete_image(tools->window, tools->main_character);
	if (button == MLX_KEY_W)
	{
		text = mlx_load_png("Textures/mainchar_up.png");
		tools->main_character = mlx_texture_to_image(tools->window, text);
	}
	if (button == MLX_KEY_D)
	{
		text = mlx_load_png("Textures/mainchar_right.png");
		tools->main_character = mlx_texture_to_image(tools->window, text);
	}
	if (button == MLX_KEY_A)
	{
		text = mlx_load_png("Textures/mainchar_left.png");
		tools->main_character = mlx_texture_to_image(tools->window, text);
	}
	if (button == MLX_KEY_S)
	{
		text = mlx_load_png("Textures/mainchar_normal.png");
		tools->main_character = mlx_texture_to_image(tools->window, text);
	}
	mlx_delete_texture(text);
}

int	steps_manage(t_tools *tools, enum keys button)
{
	char	**map;

	map = tools->map;
	if (button == MLX_KEY_W)
	{
		if (map[tools->coords_char.y - 1][tools->coords_char.x] != '1')
			return (tools->coords_char.y -= 1, 1);
	}
	if (button == MLX_KEY_D)
	{
		if (map[tools->coords_char.y][tools->coords_char.x + 1] != '1')
			return (tools->coords_char.x += 1, 1);
	}
	if (button == MLX_KEY_A)
	{
		if (map[tools->coords_char.y][tools->coords_char.x - 1] != '1')
			return (tools->coords_char.x -= 1, 1);
	}
	if (button == MLX_KEY_S)
	{
		if (map[tools->coords_char.y + 1][tools->coords_char.x] != '1')
			return (tools->coords_char.y += 1, 1);
	}
	return (0);
}

t_tools	*get_char_coords(t_tools *coords)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	x = 0;
	map = coords->map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				coords->coords_char.x = x;
				coords->coords_char.y = y;
				return (coords);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (coords);
}

int	move_character(t_tools *tools, enum keys button)
{
	static int	moves = 0;

	choose_png(tools, button);
	if (steps_manage(tools, button) != 0)
	{
		moves++;
		ft_printf("%d\n", moves);
		tools->animation = true;
		tools->datakey.key = button;
	}
	else
		mlx_image_to_window(tools->window, tools->main_character,
			tools->coords_char.x * 64 + 13, tools->coords_char.y * 64);
	return (moves);
}

void	ft_movement(mlx_key_data_t keydata, void *param)
{
	t_tools			*tools;
	int				moves;

	moves = 0;
	tools = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			moves = move_character(tools, MLX_KEY_W);
		if (keydata.key == MLX_KEY_D)
			moves = move_character(tools, MLX_KEY_D);
		if (keydata.key == MLX_KEY_A)
			moves = move_character(tools, MLX_KEY_A);
		if (keydata.key == MLX_KEY_S)
			moves = move_character(tools, MLX_KEY_S);
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(tools->window);
	}
}

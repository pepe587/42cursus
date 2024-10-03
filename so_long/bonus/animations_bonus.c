/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:36:56 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 22:03:03 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <stdlib.h>

void	string_moves(t_tools *tools, int moves)
{
	char				*strmoves;
	char				*num;

	num = ft_itoa(moves);
	strmoves = ft_strjoin("Moves: ", num);
	if (tools->imgmoves != NULL)
		mlx_delete_image(tools->window, tools->imgmoves);
	tools->imgmoves = mlx_put_string(tools->window, strmoves, 64, 16);
	free(strmoves);
	free(num);
}

void	ft_frames(void *param)
{
	t_tools		*tools;

	tools = param;
	if (tools->dead == true)
		mlx_close_window(tools->window);
	else if (tools->animation == true)
	{
		tools->frames++;
		if (tools->frames == 8)
			tools->image1 = animation_1(tools);
		if (tools->frames == 16)
			tools->image2 = animation_2(tools, tools->image1);
		if (tools->frames == 24)
		{
			mlx_delete_image(tools->window, tools->image2);
			tools->frames = 0;
			tools->animation = false;
			tools->datakey.key = 0;
			mlx_image_to_window(tools->window, tools->main_character,
				(tools->coords_char.x * 64) + 13, tools->coords_char.y * 64);
			hand_collec(tools);
			hand_enemies(tools);
		}
	}
}

int	check_collecs(t_tools *tools)
{
	tools->num_collecs = tools->max_collecs
		- get_num_collec(tools->m_map);
	if (tools->max_collecs != tools->num_collecs)
		return (ft_printf("Error:\nSome collectibles are"
				" not available to the player"), 0);
	return (1);
}

int	get_num_collec(char **map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (i);
}

void	show_window(t_maplen coords, char **map)
{
	mlx_t				*window;
	t_tools				tools;
	t_tools				*ptr;

	tools.num_collecs = 0;
	tools.max_collecs = 0;
	window = mlx_init(coords.x * 64, coords.y * 64, "so_long", false);
	tools = save_tools(window, map);
	ptr = &tools;
	get_char_coords(ptr);
	ptr->max_collecs = get_num_collec(ptr->map);
	put_image(window, coords, map, tools);
	if (check_map(map, coords, ptr) == 0)
		return ;
	string_moves(ptr, 0);
	draw_enemies(ptr);
	mlx_key_hook(ptr->window, ft_movement, ptr);
	mlx_loop_hook(tools.window, ft_frames, ptr);
	mlx_loop(window);
	ft_free_matrix(tools.m_map);
	mlx_terminate(tools.window);
}

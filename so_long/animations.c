/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:36:56 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/10/24 20:35:49 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
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

static void	get_num_collec(t_tools *tools)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	tools->num_collecs = 0;
	while (tools->map[y])
	{
		while (tools->map[y][x])
		{
			if (tools->map[y][x] == 'C')
				tools->max_collecs++;
			x++;
		}
		x = 0;
		y++;
	}
}
void	show_window(t_maplen coords, char **map)
{
	mlx_t				*window;
	t_tools				tools;
	t_tools				*ptr;
	int					check;

	check = 0;
	window = mlx_init(coords.x * 64, coords.y * 64, "so_long", true);
	tools = save_tools(window, map);
	ptr = &tools;
	get_char_coords(ptr);
	get_num_collec(ptr);
	put_image(window, coords, map, tools);
	ptr->max_collecs = 0;
	if (ft_check_solvable(ptr, ptr->coords_char.x,
			ptr->coords_char.y, &check) == 0
		|| ptr->num_collecs != ptr->max_collecs)
	{
		ft_printf("Error\nEl mapa no se puede resolver");
		return ;
	}
		ft_printf("El numero de C que hay es: %d\n", ptr->max_collecs);
		ft_printf("El numero de C que debria de haber es :%d\n", ptr->max_collecs);
	string_moves(ptr, 0);
	draw_enemies(ptr);
	mlx_key_hook(ptr->window, ft_movement, ptr);
	mlx_loop_hook(tools.window, ft_frames, ptr);
	mlx_loop(window);
	mlx_terminate(tools.window);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_animation_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:17:39 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/10/12 20:12:29 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

mlx_image_t	*animation_w(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_up(1).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 13,
		tools->coords_char.y * 64 + 42);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_a(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_left(1).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 29,
		tools->coords_char.y * 64);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_s(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_down(1).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 13,
		tools->coords_char.y * 64 - 42);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_d(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_right(1).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) - 29,
		tools->coords_char.y * 64);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_1(t_tools *tools)
{
	mlx_image_t	*image;

	if (tools->datakey.key == MLX_KEY_W)
		image = animation_w(tools);
	if (tools->datakey.key == MLX_KEY_A)
		image = animation_a(tools);
	if (tools->datakey.key == MLX_KEY_S)
		image = animation_s(tools);
	if (tools->datakey.key == MLX_KEY_D)
		image = animation_d(tools);
	return (image);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_animation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:43:17 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/10/12 20:18:36 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

mlx_image_t	*animation_w2(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_up(2).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 13,
		tools->coords_char.y * 64 + 21);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_a2(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_left(2).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 6,
		tools->coords_char.y * 64);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_s2(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_down(2).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) + 13,
		tools->coords_char.y * 64 - 21);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_d2(t_tools *tools)
{
	mlx_texture_t		*text;
	mlx_image_t			*image;

	text = mlx_load_png("Textures/mainchar_running_right(2).png");
	image = mlx_texture_to_image(tools->window, text);
	mlx_image_to_window(tools->window, image, (tools->coords_char.x * 64) - 6,
		tools->coords_char.y * 64);
	mlx_delete_texture(text);
	return (image);
}

mlx_image_t	*animation_2(t_tools *tools, mlx_image_t *image1)
{
	mlx_image_t	*image;

	mlx_delete_image(tools->window, image1);
	if (tools->datakey.key == MLX_KEY_W)
		image = animation_w2(tools);
	if (tools->datakey.key == MLX_KEY_A)
		image = animation_a2(tools);
	if (tools->datakey.key == MLX_KEY_S)
		image = animation_s2(tools);
	if (tools->datakey.key == MLX_KEY_D)
		image = animation_d2(tools);
	return (image);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:24:20 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/19 19:02:11 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	putsquare(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	div;

	j = x;
	if ((unsigned)color == 0xFF000088)
		div = 2;
	else
		div = 1;
	while (j < x + (PIXEL_SIZE / div))
	{
		i = y;
		while (i < y + (PIXEL_SIZE / div))
		{
			mlx_put_pixel(cub->main_img, j, i, color);
			++i;
		}
		++j;
	}
}

void	draw_map(t_cub *cub, t_point *beg, t_point *end, t_mmap m)
{
	int	beg_x;
	int	i;
	int	j;

	j = -1;
	while ((int)beg->y < (int)end->y && ++j + 1)
	{
		beg_x = (int)beg->x;
		i = 0;
		while (beg_x < (int)end->x && cub->map.map[(int)beg->y][beg_x])
		{
			if (cub->map.map[(int)beg->y][(int)beg_x] == '0')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0x0000FFFF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == '1')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0xFFFFFFFF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == 'D')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0xFFFF00FF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == 'd')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0x00FF00FF);
			++beg_x;
			++i;
		}
		beg->y += 1;
	}
	draw_ray_minimap_x(cub, m, 0);
}

void	minimap(t_cub *cub, t_point *pos)
{
	t_point	beg;
	t_point	end;
	t_mmap	m;

	beg.x = pos->x - (int)pos->x % 10;
	if (beg.x < 0)
		beg.x = -1;
	beg.y = pos->y - (int)pos->y % 10;
	if (beg.y < 0)
		beg.y = -1;
	end.x = (beg.x + 10);
	end.y = (beg.y + 10);
	if (end.y > ft_arrnum(cub->map.map))
		end.y = ft_arrnum(cub->map.map);
	draw_map(cub, &beg, &end, m);
	mlx_put_pixel(cub->main_img, (fmod(pos->x, 10) * PIXEL_SIZE),
		(fmod(pos->y, 10) * PIXEL_SIZE), 0xFF000088);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:04:05 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 22:12:24 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_tools	save_tools(mlx_t *window, char	**map)
{
	t_tools				tools;
	mlx_texture_t		*text;

	text = mlx_load_png("Textures/floor.png");
	tools.floor = mlx_texture_to_image(window, text);
	mlx_delete_texture(text);
	text = mlx_load_png("Textures/wall.png");
	tools.wall = mlx_texture_to_image(window, text);
	mlx_delete_texture(text);
	text = mlx_load_png("Textures/exit.png");
	tools.exit = mlx_texture_to_image(window, text);
	mlx_delete_texture(text);
	text = mlx_load_png("Textures/mainchar_normal.png");
	tools.main_character = mlx_texture_to_image(window, text);
	mlx_delete_texture(text);
	text = mlx_load_png("Textures/master-ball.png");
	tools.collec = mlx_texture_to_image(window, text);
	mlx_delete_texture(text);
	tools.window = window;
	tools.map = map;
	tools.frames = 0;
	tools.animation = false;
	tools.dead = false;
	tools.m_map = cpymatrix(map);
	return (tools);
}

void	put_image(mlx_t *window, t_maplen coords, char **map, t_tools textures)
{
	int					x;
	int					y;

	y = 0;
	x = 0;
	while (y != coords.y && x != coords.x)
	{
		while (x < coords.x)
		{
			mlx_image_to_window(window, textures.floor, x * 64, y * 64);
			if (map[y][x] == 'P')
				mlx_image_to_window(window, textures.main_character,
					(x * 64) + 13, y * 64);
			if (map[y][x] == 'E')
				mlx_image_to_window(window, textures.exit, x * 64, y * 64);
			if (map[y][x] == 'C')
				mlx_image_to_window(window, textures.collec, x * 64, y * 64);
			if (map[y][x] == '1')
				mlx_image_to_window(window, textures.wall, x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
}

int	get_bytesmap(char *str)
{
	int			len;
	char		buffer[1024];
	int			x;

	buffer[1023] = '\0';
	len = 0;
	x = open(str, O_RDONLY);
	if (x == -1)
	{
		ft_printf("%s", "Map not found\n");
		return (-1);
	}
	while (read(x, buffer, 1))
		len++;
	close(x);
	if (len == 0)
		return (ft_printf("Error:\nThe file is empty"), -1);
	return (len);
}

char	**save_map(char *str)
{
	char	*buffer;
	char	**mapa;
	int		hash;
	int		lenmap;

	lenmap = get_bytesmap(str);
	if (lenmap == -1)
		return (NULL);
	hash = open(str, O_RDONLY);
	buffer = malloc((lenmap + 1) * sizeof(char));
	buffer[lenmap] = '\0';
	read(hash, buffer, lenmap);
	close(hash);
	mapa = my_split(buffer, 10);
	if (!mapa)
		ft_printf("Error\nMap with interspersed line breaks\n");
	free(buffer);
	return (mapa);
}

t_maplen	get_coordsmap(char **map)
{
	struct s_maplen		coords;
	int					x;
	int					y;

	x = 0;
	y = 0;
	while (map[0][x])
		x++;
	coords.x = x;
	while (map[y])
		y++;
	coords.y = y;
	return (coords);
}

/*void ft_leaks()
{
	system("leaks -q a.out");
}*/

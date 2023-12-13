/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:01:17 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:27 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_objects
{
	int	c;
	int	e;
	int	p;
}	t_objects;

typedef struct s_maplen
{
	int	x;
	int	y;
}	t_maplen;

typedef struct s_tools
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*main_character;
	mlx_image_t		*exit;
	mlx_image_t		*collec;
	mlx_t			*window;
	t_maplen		coords_char;
	char			**map;
	int				frames;
	bool			animation;
	mlx_key_data_t	datakey;
	mlx_image_t		*image1;
	mlx_image_t		*image2;
	mlx_image_t		*zubat;
	bool			dead;
	mlx_image_t		*imgmoves;
	int				num_collecs;
	t_maplen		proportions;
	char			**m_map;
	int				max_collecs;
}	t_tools;

int						check_map_walls(char **map, t_maplen coords);
int						get_bytesmap(char *str);
char					**save_map(char *str);
t_maplen				get_coordsmap(char **map);
void					show_window(t_maplen coords, char **map);
int						check_map_rectangular(char **map, t_maplen coords);
int						check_map_objs(char **map, t_maplen coords);
int						check_map(char **map, t_maplen coords, t_tools *tools);
int						hand_character(t_tools *tools);
void					ft_movement(mlx_key_data_t keydata, void *param);
t_tools					*get_char_coords(t_tools *coords);
void					hand_collec(t_tools *tools);
int						check_extension(char *str);
void					string_moves(t_tools *tools, int moves);
void					ft_frames(void *param);
mlx_image_t				*animation_1(t_tools *tools);
mlx_image_t				*animation_2(t_tools *tools, mlx_image_t *image1);
void					draw_enemies(t_tools *tools);
void					hand_enemies(t_tools *tools);
void					ft_free_matrix(char **map);
void					show_window(t_maplen coords, char **map);
t_tools					save_tools(mlx_t *window, char	**map);
void					put_image(mlx_t *window, t_maplen coords,
							char **map, t_tools textures);
char					**cpymatrix(char **array);
int						get_num_collec(char **map);
int						check_collecs(t_tools *tools);
char					**my_split(const char *s, char c);

#endif
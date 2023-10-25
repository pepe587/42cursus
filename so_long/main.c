/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:30:28 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/10/24 19:41:41 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char				**map;
	t_maplen			coords;

	if (argc < 2)
		return (ft_printf("%s", "Error:\nningun mapa introducido\n"), 0);
	if (check_extension(argv[1]) == 0)
		return (0);
	map = save_map(argv[1]);
	if (!map)
		return (0);
	coords = get_coordsmap(map);
	if (check_map(map, coords) == 0)
		return (0);
	show_window(coords, map);
	ft_free_matrix(map);
}

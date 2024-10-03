/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:30:28 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 21:59:48 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	ft_leaks()
{
	system("leaks -q so_long");
}*/

/* Put this line in the main to check the memory leaks atexit(ft_leaks);*/

int	main(int argc, char **argv)
{
	char				**map;
	t_maplen			coords;

	if (argc < 2)
		return (ft_printf("%s", "Error:\nNo map introduced\n"), 0);
	if (check_extension(argv[1]) == 0)
		return (0);
	map = save_map(argv[1]);
	if (!map)
		return (0);
	coords = get_coordsmap(map);
	show_window(coords, map);
	ft_free_matrix(map);
}

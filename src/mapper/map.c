/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:10:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 01:56:53 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*m(void)
{
	static t_map	map_instance;

	return &map_instance;
}

void	init_map(char **map)
{
	m()->matrix = map;
	m()->width = ft_matrix_width(m()->matrix);
	m()->height = ft_matrix_height(m()->matrix);
}

void	check_map(t_map map)
{
	if (!check_width(map.matrix, map.width))
		on_error("Please insert a valid map, some size is wrong.\n");
	if (!check_retangular(map.width, map.height))
		on_error("Please insert a valid map, the are is not retangular\n");
	if (!check_border_walls(map.matrix, map.width, map.height))
		on_error("Please insert a valid map, some wall is wrong.\n");
	if (!check_valid_components(map.matrix))
		on_error("Please insert a valid map, something is missing\n");
	if (!check_components_number(map.matrix))
		on_error("Please insert a valid map, the map don't fit into the rules\n");
}

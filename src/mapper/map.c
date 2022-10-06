/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:10:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/06 03:30:27 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*m(void)
{
	static t_map	map_instance;

	return &map_instance;
}

void	m__init(char **map)
{
	m()->matrix = map;
	m()->width = m__width(m()->matrix);
	m()->height = m__height(m()->matrix);
}

void	m__check(t_map map)
{
	if (!m__check_width(map.matrix, map.width))
		on_error("Please insert a valid map, some size is wrong.\n");
	if (!m__check_retangular(map.width, map.height))
		on_error("Please insert a valid map, quadratic maps are not allowed\n");
	if (!m__check_border_walls(map.matrix, map.width, map.height))
		on_error("Please insert a valid map, some wall is wrong.\n");
	if (!m__check_valid_components(map.matrix))
		on_error("Please insert a valid map, something is missing\n");
	if (!m__check_components_number(map.matrix))
		on_error("Please insert a valid map, the map don't fit into the rules\n");
}

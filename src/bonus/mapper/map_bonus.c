/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:10:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*m(void)
{
	static t_map	map_instance;

	return (&map_instance);
}

t_map	m__init(char **map)
{
	m()->matrix = map;
	m()->width = m__width(m()->matrix);
	m()->height = m__height(m()->matrix);
	m()->player = m__get_elm_position(C_PLAYER);
	m()->collectables = m__get_elm_positions(C_COLLECTABLE);
	m()->collectables_amount = m__get_elm_amount(C_COLLECTABLE);
	return (*m());
}

char	**m__generate_map_from(char *filename)
{
	char	*raw_map;

	raw_map = ft_pread_file(filename);
	if (!raw_map)
		on_error("The map file couldn't be opened\n");
	return (ft_psplit(raw_map, '\n'));
}

void	m__basic_check(char **map)
{
	int	width;
	int	height;

	width = m__width(map);
	height = m__height(map);
	if (!m__check_width(map, width))
		on_error("Invalid map: some size is wrong.\n");
	if (!m__check_retangular(width, height))
		on_error("Invalid map: quadratic maps are not allowed\n");
	if (!m__check_border_walls(map, width, height))
		on_error("Invalid map: some wall is wrong.\n");
	if (!m__check_valid_elms(map))
		on_error("Invalid map: something is missing\n");
	if (!m__check_elms_number(map))
		on_error("Invalid map: the map don't fit into the rules\n");
}

void	m__complex_check(t_map map)
{
	if (!m__check_path(map))
		on_error("Invalid map: the map have an invalid path\n");
}

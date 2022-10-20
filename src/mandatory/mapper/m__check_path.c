/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:54:55 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/20 23:52:57 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_safe(char **map, t_position pos)
{
	char	c;

	c = map[pos.y][pos.x];
	return (c != C_WALL && c != '-' && c != C_EXIT);
}

static int	validate_path(char **map, t_position from, t_position to)
{
	t_position	up;
	t_position	down;
	t_position	left;
	t_position	right;

	up = new_position(from.x, from.y - 1);
	down = new_position(from.x, from.y + 1);
	left = new_position(from.x - 1, from.y);
	right = new_position(from.x + 1, from.y);
	if (from.y == to.y && from.x == to.x)
		return (1);
	if (is_safe(map, from))
	{
		map[from.y][from.x] = '-';
		if (validate_path(map, up, to))
			return (1);
		if (validate_path(map, down, to))
			return (1);
		if (validate_path(map, left, to))
			return (1);
		if (validate_path(map, right, to))
			return (1);
	}
	return (0);
}

static int	validate_collectables_path(t_map map)
{
	char		**map_copy;
	int			collectable_amount;
	int			i;

	i = 0;
	collectable_amount = m__get_elm_amount(C_COLLECTABLE);
	while (i < collectable_amount)
	{
		map_copy = ft_mtxsdup(map.matrix, map.height);
		if (!validate_path(map_copy, map.player, map.collectables[i]))
			return (0);
		i++;
	}
	return (1);
}

int	m__check_path(t_map map)
{
	char	**map_copy;

	if (!validate_collectables_path(map))
		return (0);
	map_copy = ft_mtxsdup(map.matrix, map.height);
	return (validate_path(map_copy, m()->player, m__get_elm_position(C_EXIT)));
}

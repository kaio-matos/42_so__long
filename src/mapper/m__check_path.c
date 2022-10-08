/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:54:55 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/08 03:00:28 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_position	get_player_position(char **map)
{
	t_position	pos;
	char		**map;

	map = m()->matrix;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (m__is_player(map[pos.y][pos.x]))
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	is_safe(char **map, t_position pos)
{
	return (map[pos.y][pos.x] != C_WALL && map[pos.y][pos.x] != '-');
}

int	m__validate_path(char **map, t_position position)
{
	t_position	up;
	t_position	down;
	t_position	left;
	t_position	right;

	up		= new_position(position.x, position.y - 1);
	down	= new_position(position.x, position.y + 1);
	left	= new_position(position.x - 1, position.y);
	right	= new_position(position.x + 1, position.y);

	if (map[pos.y][pos.x] == C_EXIT) return (1);

	if (is_safe(map, position))
	{
		map[pos.y][pos.x] = '-';
		if (m__validate_path(map, up))
			return (1);
		if (m__validate_path(map, down))
			return (1);
		if (m__validate_path(map, left))
			return (1);
		if (m__validate_path(map, right))
			return (1);
	}
	return (0);
}

void	m__check_path(char **map)
{
	char	**map_copy;

	map_copy = ft_mtxcpy(map);
	m__validate_path(map_copy, get_player_position(map));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__checkers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:53:45 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:22:52 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	m__check_retangular(int width, int height)
{
	if (width == height)
		return (0);
	return (1);
}

int	m__check_width(char **map, size_t width)
{
	int	i;

	i = -1;
	while (map[++i])
		if (width != ft_strlen(map[i]))
			return (0);
	return (1);
}

int	m__check_border_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (m__is_wall(map[0][i]))
		i++;
	if (width != i)
		return (0);
	i = 0;
	while (m__is_wall(map[height - 1][i]))
		i++;
	if (width != i)
		return (0);
	i = 0;
	while (map[i] && m__is_wall(map[i][0]))
		i++;
	if (height != i)
		return (0);
	i = 0;
	while (map[i] && m__is_wall(map[i][width - 1]))
		i++;
	if (height != i)
		return (0);
	return (1);
}

int	m__check_valid_elms(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!m__is_collectable(map[i][j]) && !m__is_exit(map[i][j]) &&
				!m__is_ground(map[i][j]) && !m__is_wall(map[i][j]) &&
				!m__is_player(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	m__check_elms_number(char **map)
{
	int	i;
	int	j;
	int	players;
	int	exits;
	int	collectables;

	i = 0;
	players = 0;
	exits = 0;
	collectables = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			players += m__is_player(map[i][j]);
			exits += m__is_exit(map[i][j]);
			collectables += m__is_collectable(map[i][j]);
			j++;
		}
		i++;
	}
	if (players != 1 || exits != 1 || collectables <= 0)
		return (0);
	return (1);
}

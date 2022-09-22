/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:10:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/22 02:42:19 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_retangular(int width, int height)
{
	if (width == height)
		return (0);
	return (1);
}

int	check_width(char **map, size_t width)
{
	int	i;

	i = -1;
	while (map[++i])
		if (width != ft_strlen(map[i]))
			return (0);
	return (1);
}

int	check_border_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (is_wall(map[0][i]))
		i++;
	if (width != i)
		return (0);
	i = 0;
	while (is_wall(map[height - 1][i]))
		i++;
	if (width != i)
		return (0);
	i = 0;
	while (map[i] && is_wall(map[i][0]))
		i++;
	if (height != i)
		return (0);
	i = 0;
	while (map[i] && is_wall(map[i][width - 1]))
		i++;
	if (height != i)
		return (0);
	return (1);
}

int	check_valid_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_collectable(map[i][j]) && !is_exit(map[i][j]) &&
				!is_ground(map[i][j]) && !is_wall(map[i][j]) &&
				!is_player(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_components_number(char **map)
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
			if (is_player(map[i][j]))
				players++;
			if (is_exit(map[i][j]))
				exits++;
			if (is_collectable(map[i][j]))
				collectables++;
			j++;
		}
		i++;
	}
	if (players != 1 || exits != 1 || collectables <= 0)
		return (0);
	return (1);
}

void	check_map(char *map)
{
	char	**map_matrix;
	size_t	width;
	size_t	height;

	map_matrix = ft_split(map, '\n');
	width = ft_matrix_width(map_matrix);
	height = ft_matrix_height(map_matrix);
	if (!check_width(map_matrix, width))
		on_error("Please insert a valid map, some size is wrong.\n");
	if (!check_retangular(width, height))
		on_error("Please insert a valid map, the are is not retangular\n");
	if (!check_border_walls(map_matrix, width, height))
		on_error("Please insert a valid map, some wall is wrong.\n");
	if (!check_valid_components(map_matrix))
		on_error("Please insert a valid map, something is missing\n");
	if (!check_components_number(map_matrix))
		on_error("Please insert a valid map, the map don't fit into the rules\n");
}

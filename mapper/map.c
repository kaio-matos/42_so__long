/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:10:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/24 01:53:42 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_map(char **map_matrix)
{
	size_t	width;
	size_t	height;

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

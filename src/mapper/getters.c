/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:53:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/27 01:00:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_position	get_player_pos(char **map)
{
	t_position	pos;

	pos.x = 0;
	while (map[pos.x])
	{
		pos.y = 0;
		while (map[pos.x][pos.y])
		{
			if (is_player(map[pos.x][pos.y]))
				return (pos);
			pos.y++;
		}
		pos.x++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

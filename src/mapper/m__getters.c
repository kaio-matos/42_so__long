/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:53:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 02:04:05 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	m__get_pos_component(t_position pos)
{
	return(m()->matrix[pos.y][pos.x]);
}

t_position	m__get_player_current_position()
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

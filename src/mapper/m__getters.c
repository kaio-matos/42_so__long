/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:53:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/05 05:21:00 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	m__get_component(t_position pos)
{
	return(m()->matrix[pos.y][pos.x]);
}

t_position	m__get_player(void)
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

int	m__get_component_amount(int (*is_valid_component) (char))
{
	int	i;
	int	j;
	int	counted;

	i = 0;
	counted = 0;
	while (m()->matrix[i])
	{
		j = 0;
		while (m()->matrix[i][j])
		{
			counted += is_valid_component(m()->matrix[i][j]);
			j++;
		}
		i++;
	}
	return (counted);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:53:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/11 02:49:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	m__get_component(t_position pos)
{
	return(m()->matrix[pos.y][pos.x]);
}

t_position	m__get_component_position(char c)
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
			if (map[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

t_position	*m__get_collectables(void)
{
	t_position	*positions;
	t_position	pos;
	int			i;
	char		**map;

	map = m()->matrix;
	positions = ft_palloc(m__get_component_amount(&m__is_collectable) * sizeof(t_position));
	pos.y = 0;
	i = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (m__is_collectable(map[pos.y][pos.x]))
			{
				positions[i] = pos;
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (positions);
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

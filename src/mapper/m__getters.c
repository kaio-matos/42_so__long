/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:53:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/12 01:29:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	m__get_elm(t_position pos)
{
	return(m()->matrix[pos.y][pos.x]);
}

t_position	m__get_elm_position(char c)
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
	return (new_position(-1, -1));
}

t_position	*m__get_elm_positions(char c)
{
	t_position	*positions;
	t_position	pos;
	int			i;
	char		**map;
	int			amount;

	pos.y = 0;
	i = 0;
	map = m()->matrix;
	amount = m__get_elm_amount(c);
	positions = ft_palloc((amount + 1) * sizeof(t_position));
	while (i < amount && map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == c)
			{
				positions[i] = pos;
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
	positions[amount] = new_position(-1, -1);
	return (positions);
}

int	m__get_elm_amount(char c)
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
			if (c == m()->matrix[i][j])
				counted++;
			j++;
		}
		i++;
	}
	return (counted);
}

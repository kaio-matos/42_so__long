/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__is_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:32:20 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 02:04:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	m__is_player(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

int	m__is_collectable(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	m__is_exit(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

int	m__is_ground(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	m__is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

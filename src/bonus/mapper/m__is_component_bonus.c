/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__is_component_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:32:20 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	m__is_player(char c)
{
	if (c == C_PLAYER)
		return (1);
	return (0);
}

int	m__is_collectable(char c)
{
	if (c == C_COLLECTABLE)
		return (1);
	return (0);
}

int	m__is_exit(char c)
{
	if (c == C_EXIT)
		return (1);
	return (0);
}

int	m__is_ground(char c)
{
	if (c == C_GROUND)
		return (1);
	return (0);
}

int	m__is_wall(char c)
{
	if (c == C_WALL)
		return (1);
	return (0);
}

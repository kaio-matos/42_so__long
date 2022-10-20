/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__setters_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 05:52:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	m__set_elm(t_position position, char c)
{
	m()->matrix[position.y][position.x] = c;
}

void	m__swap_char(t_position current_position, t_position end_position)
{
	char	old_char;
	char	new_char;

	old_char = m__get_elm(current_position);
	new_char = m__get_elm(end_position);
	m__set_elm(current_position, new_char);
	m__set_elm(end_position, old_char);
}

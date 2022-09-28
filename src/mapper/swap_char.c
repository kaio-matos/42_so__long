/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:51:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:21:59 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	swap_char(t_position current_position, t_position end_position)
{
	char	old_char;
	char	new_char;

	old_char = m()->matrix[current_position.y][current_position.x];
	new_char = m()->matrix[end_position.y][end_position.x];
	m()->matrix[current_position.y][current_position.x] = new_char;
	m()->matrix[end_position.y][end_position.x] = old_char;
}
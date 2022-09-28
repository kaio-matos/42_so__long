/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:25:37 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:39:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_position	position(int x, int y)
{
	t_position	pos;
	pos.x = x;
	pos.y = y;
	return (pos);
}

void	move_player(int pressed_key)
{
	t_position	player_pos;

	player_pos = get_player_pos();
	if (pressed_key == KEY_W || pressed_key == KEY_UP)
		swap_char(player_pos, position(player_pos.x, player_pos.y - 1));
	render(m());
}
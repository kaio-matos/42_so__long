/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:25:37 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/18 03:00:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(int x, int y)
{
	t_position	position_to_go;

	position_to_go = new_position(game()->player.x + x, game()->player.y + y);
	game__set_player(position_to_go);
}

void	move_player_manager(int pressed_key)
{
	if (pressed_key == KEY_W || pressed_key == KEY_UP)
		move_player(0, -1);
	if (pressed_key == KEY_S || pressed_key == KEY_DOWN)
		move_player(0, 1);
	if (pressed_key == KEY_A || pressed_key == KEY_LEFT)
		move_player(-1, 0);
	if (pressed_key == KEY_D || pressed_key == KEY_RIGHT)
		move_player(1, 0);
}

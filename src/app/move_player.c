/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:25:37 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:43:10 by kmatos-s         ###   ########.fr       */
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
	if (pressed_key == KEY_S || pressed_key == KEY_DOWN)
		swap_char(player_pos, position(player_pos.x, player_pos.y + 1));
	if (pressed_key == KEY_A || pressed_key == KEY_LEFT)
		swap_char(player_pos, position(player_pos.x - 1, player_pos.y));
	if (pressed_key == KEY_D || pressed_key == KEY_RIGHT)
		swap_char(player_pos, position(player_pos.x + 1, player_pos.y));
	render(m()); // ! REMOVE LATER
}
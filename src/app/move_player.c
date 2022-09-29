/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:25:37 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/29 05:53:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static t_position	position(int x, int y)
{
	t_position	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

static void	move_player(int x, int y)
{
	char		swaping_component;
	t_position	player_pos;
	t_position	position_to_go;

	player_pos = get_player_current_position();
	position_to_go = position(player_pos.x + x, player_pos.y + y);
	swaping_component = get_pos_component(position_to_go);
	if (is_wall(swaping_component))
		return ;
	swap_char(player_pos, position_to_go);
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
	render(m()); // ! REMOVE LATER
}
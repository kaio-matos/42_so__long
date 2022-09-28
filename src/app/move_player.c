/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:25:37 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 03:04:20 by kmatos-s         ###   ########.fr       */
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

int	can_move_player(t_position position_to_move)
{
	char	swaping_component;

	swaping_component = get_pos_component(position_to_move);
	if (is_wall(swaping_component))
		return (0);
	return (1);
}

void	move_player(int pressed_key)
{
	t_position	player_pos;
	t_position position_to_go_up;
	t_position position_to_go_down;
	t_position position_to_go_left;
	t_position position_to_go_right;

	player_pos = get_player_current_position();
	position_to_go_up    = position(player_pos.x, player_pos.y - 1);
	position_to_go_down  = position(player_pos.x, player_pos.y + 1);
	position_to_go_left  = position(player_pos.x - 1, player_pos.y);
	position_to_go_right = position(player_pos.x + 1, player_pos.y);

	if ((pressed_key == KEY_W || pressed_key == KEY_UP) && can_move_player(position_to_go_up))
		swap_char(player_pos, position_to_go_up);
	if ((pressed_key == KEY_S || pressed_key == KEY_DOWN) && can_move_player(position_to_go_down))
		swap_char(player_pos, position_to_go_down);
	if ((pressed_key == KEY_A || pressed_key == KEY_LEFT) && can_move_player(position_to_go_left))
		swap_char(player_pos, position_to_go_left);
	if ((pressed_key == KEY_D || pressed_key == KEY_RIGHT) && can_move_player(position_to_go_right))
		swap_char(player_pos, position_to_go_right);
	// render(m()); // ! REMOVE LATER
}
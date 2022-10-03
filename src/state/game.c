/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:08:35 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 01:40:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game	*game()
{
	static t_game	game_instance;

	return &game_instance;
}

void	init_game()
{
	game()->player = get_player_current_position();
	game()->ended = 0;
	game()->collected = 0;
}

void	game__set_player(t_position player)
{
	swap_char(game()->player, player);
	game()->player = player;
}

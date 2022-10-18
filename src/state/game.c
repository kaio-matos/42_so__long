/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:08:35 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/18 03:00:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game(void)
{
	static t_game	game_instance;

	return (&game_instance);
}

void	game__init(t_map map)
{
	game()->player = map.player;
	game()->collectables = m__get_elm_amount(C_COLLECTABLE);
	game()->can_end = 0;
	game()->collected = 0;
	game()->movements = 0;
}

static void	game__add_movements(void)
{
	game()->movements += 1;
	ft_printf("Movements: %i\n", game()->movements);
}

static void	game__add_colleted(void)
{
	game()->collected += 1;
	if (game()->collected == game()->collectables)
		game()->can_end = 1;
}

void	game__set_player(t_position new_position)
{
	char	swaping_component;

	swaping_component = m__get_elm(new_position);
	if (m__is_wall(swaping_component) || (m__is_exit(swaping_component)
			&& !game()->can_end))
		return ;
	if (m__is_collectable(swaping_component))
	{
		m__set_elm(game()->player, C_GROUND);
		m__set_elm(new_position, C_PLAYER);
		game__add_colleted();
	}
	else if (m__is_exit(swaping_component))
		ft_exit(0);
	else
		m__swap_char(game()->player, new_position);
	game__add_movements();
	game()->player = new_position;
}

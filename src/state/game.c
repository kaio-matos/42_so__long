/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:08:35 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/06 04:35:10 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game	*game(void)
{
	static t_game	game_instance;

	return &game_instance;
}

void	game__init(void)
{
	game()->player = m__get_player();
	game()->collectables = m__get_component_amount(&m__is_collectable);
	game()->ended = 0;
	game()->collected = 0;
	game()->movements = 0;
}

static void	game__add_movements()
{
	game()->movements += 1;
	system("clear");
	ft_printf("Movements: %i\n", game()->movements);
}

void	game__set_player(t_position new_position)
{
	char	swaping_component;

	swaping_component = m__get_component(new_position);
	if (m__is_wall(swaping_component) || (m__is_exit(swaping_component) && game()->collected != game()->collectables))
		return ;
	if (m__is_collectable(swaping_component))
	{
		m__set_component(game()->player, C_GROUND);
		m__set_component(new_position, C_PLAYER);
		game()->collected += 1;
	}
	else if (m__is_exit(swaping_component))
	{
		game()->ended = 1;
		w__close(w());
	}
	else
	{
		m__set_component(game()->player, C_GROUND);
		m__set_component(new_position, C_PLAYER);
	}
		// m__swap_char(game()->player, new_position);
	game__add_movements();
	game()->player = new_position;
}

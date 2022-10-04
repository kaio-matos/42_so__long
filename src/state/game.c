/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:08:35 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 02:32:05 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game	*game()
{
	static t_game	game_instance;

	return &game_instance;
}

void	game__init()
{
	game()->player = m__get_player();
	game()->ended = 0;
	game()->collected = 0;
}

void	game__set_player(t_position new_position)
{
	char	swaping_component;

	swaping_component = m__get_component(new_position);
	if (m__is_wall(swaping_component))
		return ;
	if (m__is_collectable(swaping_component))
	{
		m__set_component(game()->player, '0');
		m__set_component(new_position, 'P');
		game()->collected += 1;
	}
	else
		m__swap_char(game()->player, new_position);
	game()->player = new_position;
}

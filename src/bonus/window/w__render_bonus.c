/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w__render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:33 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:22:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	**game_images(void)
{
	static void	*images[6];

	if (images[0] != NULL)
		return (images);
	images[0] = w__get_image("images/ground_32.xpm");
	images[1] = w__get_image("images/wall_32.xpm");
	images[2] = w__get_image("images/collectible_32.xpm");
	images[3] = w__get_image("images/player_32.xpm");
	images[4] = w__get_image("images/exit_deactivated_32.xpm");
	images[5] = w__get_image("images/exit_activated_32.xpm");
	return (images);
}

static void	load_images(unsigned int x, unsigned int y, char *character)
{
	t_position	pos;
	char		c;

	pos = new_position(x, y);
	c = *character;
	if (m__is_ground(c))
		return (w__put_image(game_images()[0], pos));
	if (m__is_wall(c))
		return (w__put_image(game_images()[1], pos));
	if (m__is_collectable(c))
		return (w__put_image(game_images()[2], pos));
	if (m__is_player(c))
		return (w__put_image(game_images()[3], pos));
	if (m__is_exit(c))
	{
		if (game()->can_end)
			return (w__put_image(game_images()[5], pos));
		return (w__put_image(game_images()[4], pos));
	}
}

static void	load_string(void)
{
	char	*movements;
	char	*string_to_print;

	movements = ft_itoa(game()->movements);
	string_to_print = ft_strjoin("Movements: ", movements);
	w__put_string(w()->width / 2 - PIXELS, PIXELS / 2,
		string_to_print);
	free(movements);
	free(string_to_print);
}

int	w__render(t_map *map)
{
	static unsigned int	timer;

	timer += 1;
	if (timer <= 120)
		return (0);
	if (!w())
		return (1);
	ft_mtxiteri(map->matrix, &load_images);
	load_string();
	timer = 0;
	return (0);
}

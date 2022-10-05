/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w__render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:33 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/05 05:49:06 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	**game_images(void)
{
	static void	*images[5];

	if (images[0] != NULL)
		return (images);
	images[0] = w__get_image("images/player_32.xpm");
	images[1] = w__get_image("images/collectable_32.xpm");
	images[2] = w__get_image("images/space_32.xpm");
	images[3] = w__get_image("images/wall_32.xpm");
	images[4] = w__get_image("images/exit_32.xpm");
	return (images);
}

static void	load_images(unsigned int x, unsigned int y, char *character)
{
	t_position pos;
	char	c;

	pos.x = x;
	pos.y = y;
	c = *character;
	if (m__is_player(c))
		return (w__put_image(game_images()[0], pos));
	if (m__is_collectable(c))
		return (w__put_image(game_images()[1], pos));
	if (m__is_ground(c))
		return (w__put_image(game_images()[2], pos));
	if (m__is_wall(c))
		return (w__put_image(game_images()[3], pos));
	if (m__is_exit(c))
		return (w__put_image(game_images()[4], pos));
}

int	w__render(t_map *map)
{
	if (!w())
		return (1);
	ft_mtxiteri(map->matrix, &load_images);
	return (0);
}

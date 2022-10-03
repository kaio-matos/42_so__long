/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w__render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:33 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 01:49:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	load_images(unsigned int x, unsigned int y, char *character)
{
	t_position pos;
	char	c;

	pos.x = x;
	pos.y = y;
	c = *character;
	if (is_player(c))
		return (w__put_image("images/player_32.xpm", pos));
	if (is_collectable(c))
		return (w__put_image("images/collectable_32.xpm", pos));
	if (is_ground(c))
		return (w__put_image("images/space_32.xpm", pos));
	if (is_wall(c))
		return (w__put_image("images/wall_32.xpm", pos));
	if (is_exit(c))
		return (w__put_image("images/exit_32.xpm", pos));
}

int	w__render(t_map *map)
{
	if (!w())
		return (1);
	ft_mtxiteri(map->matrix, &load_images);
	return (0);
}

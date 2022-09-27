/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:16:33 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:31:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	load(unsigned int x, unsigned int y, char *character)
{
	t_position pos;
	char	c;

	pos.x = x;
	pos.y = y;
	c = *character;
	if (is_player(c))
		return (put_image("images/player_32.xpm", pos));
	if (is_collectable(c))
		return (put_image("images/collectable_32.xpm", pos));
	if (is_ground(c))
		return (put_image("images/space_32.xpm", pos));
	if (is_wall(c))
		return (put_image("images/wall_32.xpm", pos));
	if (is_exit(c))
		return (put_image("images/exit_32.xpm", pos));
}

void	load_images(char **map)
{
	ft_mtxiteri(map, &load);
}


int	render(t_map *map)
{
	if (!w())
		return (1);
	load_images(map->matrix);
	return (0);
}

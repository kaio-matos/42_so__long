/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:07:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/22 02:16:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_map *map, t_window *window, t_game *game)
{
	game->initiated = 1;
	w__open();
	mlx_loop_hook(window->init, w__render, map);
	mlx_hook(window->window, 17, WINDOW_X, w__close, NULL);
	mlx_key_hook(window->window, e__key_press, NULL);
	mlx_loop(window->init);
	mlx_loop_end(window->init);
}

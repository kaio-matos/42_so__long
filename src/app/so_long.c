/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:07:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 01:36:58 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	so_long(t_map map)
{
	init_window(map.width * PIXELS, map.height * PIXELS);
	render(&map);
	// mlx_loop_hook(w()->init, render, &map);
	mlx_hook(w()->window, 17, 1 << 24, close_window, w());
	mlx_key_hook(w()->window, key_press, w());
	mlx_loop(w()->init);
	mlx_loop_end(w()->init);
	// mlx_destroy_display(w()->init);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:33:32 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/27 01:10:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_window	init_window(int width, int height)
{
	t_window window;

	window.width = width;
	window.height = height;
	window.init = mlx_init();
	if(!window.init)
		on_error("MLX could not be initialized\n");
	window.window = mlx_new_window(window.init, window.width, window.height, "So_Long");
	if(!window.window)
	{
		free(window.init);
		on_error("MLX window could be opened\n");
	}
	return (window);
}

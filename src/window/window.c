/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:33:32 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 01:38:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_window	*w(void)
{
	static t_window	window_instance;

	return &window_instance;
}

void	init_window(int width, int height)
{
	t_window	*win;

	win = w();
	win->width = width;
	win->height = height;
	win->init = mlx_init();
	memory(PUSH, win->init);
	if(!win->init)
		on_error("MLX could not be initialized\n");
	win->window = mlx_new_window(win->init, win->width, win->height, "So_Long");
	memory(PUSH, win->window);
	if(!win->window)
		on_error("MLX window could be opened\n");
}

int	close_window(t_window *window)
{
	if (window->window)
		mlx_destroy_window(window->init, window->window);
	return (0);
}
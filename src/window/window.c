/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:33:32 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/12 01:45:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_window	*w(void)
{
	static t_window	window_instance;

	return &window_instance;
}

void	w__init(int width, int height)
{
	t_window	*win;

	win = w();
	win->width = width;
	win->height = height;
	win->init = mlx_init();
	if(!win->init)
		on_error("MLX could not be initialized\n");
	win->window = mlx_new_window(win->init, win->width, win->height, "So_Long");
	if(!win->window)
		on_error("MLX window could be opened\n");
}

int	w__close(t_window *window)
{
	ft_exit(0);
	return (0);
}
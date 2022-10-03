/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:07:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 01:48:09 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void		so_long()
{
	w__init(m()->width * PIXELS, m()->height * PIXELS);
	init_game();
	w__render(m());
	// mlx_loop_hook(w()->init, w__render, &map);
	mlx_hook(w()->window, 17, 1 << 24, w__close, w());
	mlx_key_hook(w()->window, key_press, w());
	mlx_loop(w()->init);
	mlx_loop_end(w()->init);
	// mlx_destroy_display(w()->init);
}
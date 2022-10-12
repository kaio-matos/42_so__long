/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:07:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/12 02:34:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	so_long(void)
{
	w__init(m()->width * PIXELS, m()->height * PIXELS);
	game__init();
	mlx_loop_hook(w()->init, w__render, m());
	mlx_hook(w()->window, 17, 1 << 24, w__close, NULL);
	mlx_key_hook(w()->window, e__key_press, NULL);
	mlx_loop(w()->init);
	mlx_loop_end(w()->init);
}

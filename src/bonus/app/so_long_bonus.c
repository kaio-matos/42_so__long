/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:07:05 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long(void)
{
	w__open();
	mlx_loop_hook(w()->init, w__render, m());
	mlx_hook(w()->window, 17, WINDOW_X, w__close, NULL);
	mlx_key_hook(w()->window, e__key_press, NULL);
	mlx_loop(w()->init);
	mlx_loop_end(w()->init);
}

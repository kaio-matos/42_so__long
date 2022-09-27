/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:34:55 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 01:37:28 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_press(int key, t_window *window)
{
	if (key == KEY_ESC)
		close_window(window);
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		ft_printf("wasd");
		// move_player(key, window);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		ft_printf("up down left right");
		// move_player(key, window);
	return (0);
}
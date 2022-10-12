/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e__key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:34:55 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/12 02:33:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	e__key_press(int key)
{
	if (key == KEY_ESC)
		ft_exit(0);
	else if (key == KEY_W || key == KEY_S
		|| key == KEY_A || key == KEY_D)
		move_player_manager(key);
	else if (key == KEY_UP || key == KEY_DOWN
		|| key == KEY_LEFT || key == KEY_RIGHT)
		move_player_manager(key);
	return (0);
}

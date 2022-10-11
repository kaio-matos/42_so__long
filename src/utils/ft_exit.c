/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 02:51:59 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/12 01:42:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_exit(int status)
{
	free_memory();
	if (w()->init && w()->window)
		mlx_destroy_window(w()->init, w()->window);
	if (w()->init)
	{
		mlx_destroy_display(w()->init);
		free(w()->init);
	}
	exit(status);
}

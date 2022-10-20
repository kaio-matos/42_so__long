/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w__utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:53:51 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:22:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*w__get_image(char *filename)
{
	void	*img;
	int		width;
	int		height;

	width = w()->width;
	height = w()->height;
	img = mlx_xpm_file_to_image(w()->init, filename, &width, &height);
	if (!img)
		on_error("XPM image couldn't be loaded\n");
	new_memory(img, IMAGE);
	return (img);
}

void	w__put_image(void	*img, t_position position)
{
	mlx_put_image_to_window(w()->init, w()->window, img,
		position.x * PIXELS, position.y * PIXELS);
}

void	w__put_string(int x, int y, char *string)
{
	mlx_string_put(w()->init, w()->window,
		x, y,
		0x00ff00, string);
}

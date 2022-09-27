/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:53:51 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:53:14 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*get_image(char *filename)
{
	void	*img;

	img = mlx_xpm_file_to_image(w()->init, filename, &w()->width, &w()->height);
	memory(PUSH, img);
	if (!img)
		on_error("XPM image couldn't be loaded\n");
	return(img);
}

void	put_image(char *img_path, t_position position)
{
	void	*img;

	img = get_image(img_path);
	mlx_put_image_to_window(w()->init, w()->window, img,
		position.x * PIXELS, position.y * PIXELS);
}

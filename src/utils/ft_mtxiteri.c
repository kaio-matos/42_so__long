/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:01:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 01:19:19 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_mtxiteri(char **mtx, void (*f) (unsigned int, unsigned int, char *))
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (mtx[y])
	{
	    x = 0;
        while (mtx[y][x])
        {
		    f(x, y, &mtx[y][x]);
            x++;
        }
		y++;
	}
}

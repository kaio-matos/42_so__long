/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:01:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/27 03:11:26 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_mtxiteri(char **mtx, void (*f) (unsigned int, unsigned int, char *))
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (mtx[i])
	{
	    j = 0;
        while (mtx[i][j])
        {
		    f(i, j, &mtx[i][j]);
            j++;
        }
		i++;
	}
}

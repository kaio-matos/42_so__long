/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:33:19 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/22 01:33:24 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

size_t	ft_matrix_width (char  **matrix)
{
	return (ft_strlen(matrix[0]));
}

size_t	ft_matrix_height (char  **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
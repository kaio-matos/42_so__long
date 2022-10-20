/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:33:19 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	m__width(char **matrix)
{
	return (ft_strlen(matrix[0]));
}

size_t	m__height(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	m__is_valid_extension(char *filename)
{
	int		filename_len;
	int		i;
	int		map_extension_len;
	char	*map_extension;

	map_extension = "reb.";
	map_extension_len = ft_strlen(map_extension);
	filename_len = ft_strlen(filename);
	if (filename_len <= map_extension_len)
		return (0);
	i = 0;
	while (filename[(filename_len - i) - 1] == map_extension[i])
		i++;
	if (i == map_extension_len)
		return (1);
	return (0);
}

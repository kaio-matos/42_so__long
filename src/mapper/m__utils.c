/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m__utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:33:19 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 02:04:10 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

int	m__is_valid_extension(char *file_name)
{
	int		file_name_len;
	int		i;
	int		map_extension_len;
	char	*map_extension;

	map_extension = "reb.";
	map_extension_len = ft_strlen(map_extension);
	file_name_len = ft_strlen(file_name);
	if (file_name_len <= map_extension_len)
		return (0);
	i = 0;
	while (file_name[(file_name_len - i) - 1] == map_extension[i])
		i++;
	if (i == map_extension_len)
		return (1);
	return (0);
}

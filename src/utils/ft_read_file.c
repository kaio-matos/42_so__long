/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:26:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/24 01:30:51 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*ft_read_file(int fd)
{
	char	*accumulator;
	char	*current_line;
	char	*temp;

	current_line = get_next_line(fd, 25);
	accumulator = ft_strdup("");
	while (current_line && *current_line)
	{
		temp = accumulator;
		accumulator = ft_strjoin(accumulator, current_line);
		free(current_line);
		free(temp);
		current_line = get_next_line(fd, 25);
	}
	return (accumulator);
}

char	*ft_pread_file(int fd)
{
	char	*file;

	file = ft_read_file(fd);
	memory(PUSH, file);
	return (file);
}

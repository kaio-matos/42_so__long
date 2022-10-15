/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:26:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/15 03:15:15 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*ft_read_file_fd(int fd)
{
	char	*accumulator;
	char	*current_line;
	char	*temp;

	current_line = get_next_line(fd, 25);
	if (!current_line)
		return (NULL);
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

char	*ft_read_file(char *filename)
{
	int		fd;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = ft_read_file_fd(fd);
	close(fd);
	return (file);
}

char	*ft_pread_file(char *filename)
{
	char	*file;

	file = ft_read_file(filename);
	if (!file)
		on_error("Unable to read the file");
	new_memory(file, VOID);
	return (file);
}

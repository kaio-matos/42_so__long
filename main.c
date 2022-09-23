/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:53 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/24 01:23:34 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#define TEMPORARY "./maps/complex.ber"

void	initial_check(int argc, char **argv)
{
	if (argc <= 1)
		return (on_error("Please insert more arguments\n"));
	if (!argv[1])
		return (on_error("Please insert a valid argument\n"));
	if (!is_valid_map_extension(argv[1]))
		return (on_error("Please insert a valid map extension\n"));
}

char	*read_file(int fd)
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
	memory(PUSH, accumulator);
	return (accumulator);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*map;
	char	**map_matrix;

	initial_check(argc, argv);
	fd = open(TEMPORARY, O_RDONLY);
	if (fd < 0)
		on_error("The map file couldn't be opened\n");
	map = read_file(fd);
	map_matrix = ft_psplit(map, '\n');
	check_map(map_matrix);
	close(fd);
	memory(FREE, NULL);
	return (0);
}

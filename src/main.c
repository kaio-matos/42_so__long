/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:53 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:02:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	initial_check(int argc, char **argv)
{
	if (argc <= 1)
		return (on_error("Please insert more arguments\n"));
	if (!argv[1])
		return (on_error("Please insert a valid argument\n"));
	if (!is_valid_map_extension(argv[1]))
		return (on_error("Please insert a valid map extension\n"));
}

char	*read_file(char *file_name)
{
	int		fd;
	char	*raw_map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		on_error("The map file couldn't be opened\n");
	raw_map = ft_pread_file(fd);
	close(fd);
	return (raw_map);
}

int	main(int argc, char **argv)
{
	initial_check(argc, argv);
	init_map(ft_psplit(read_file(argv[1]), '\n'));
	check_map(*m());
	so_long();
	memory(FREE, NULL);
	return (0);
}

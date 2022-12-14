/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:53 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/25 04:09:46 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	program_basic_check(int argc, char **argv)
{
	if (argc != 2)
		return (on_error("Please insert one map\n"));
	if (!argv[1])
		return (on_error("Please insert a valid argument\n"));
	if (!m__is_valid_extension(argv[1]))
		return (on_error("Please insert a valid map extension\n"));
}

void	setup(char **map)
{
	t_map	computed_map;

	computed_map = m__init(map);
	w__init(computed_map.width * PIXELS, computed_map.height * PIXELS);
	game__init(computed_map);
}

int	main(int argc, char **argv)
{
	char	**map;

	program_basic_check(argc, argv);
	map = m__generate_map_from(argv[1]);
	m__basic_check(map);
	setup(map);
	m__complex_check(*m());
	so_long(m(), w(), game());
	ft_exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/22 02:56:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <fcntl.h>

/******************************************************************************\
* LOGGER																	   *
\******************************************************************************/

void		logg(char *message);
void		on_error(char *error_message);
void		on_success(char *success_message);

/******************************************************************************\
* MAPPER																	   *
\******************************************************************************/

int			is_player(char c);
int			is_collectable(char c);
int			is_exit(char c);
int			is_ground(char c);
int			is_wall(char c);
size_t		ft_matrix_width(char **matrix);
size_t		ft_matrix_height(char **matrix);
int			is_valid_map_extension(char *file_name);
int			check_retangular(int width, int height);
int			check_width(char **map, size_t width);
int			check_border_walls(char **map, int width, int height);
int			check_valid_components(char **map);
void		check_map(char **map_matrix);

/******************************************************************************\
* UTILS																	       *
\******************************************************************************/

void		ft_free_matrix(char **matrix);

#endif
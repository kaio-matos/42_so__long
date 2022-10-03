/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/04 01:40:28 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# define PIXELS 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/******************************************************************************\
* TYPES 																	   *
\******************************************************************************/

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	**matrix;
}	t_map;

typedef struct s_window
{
	void	*window;
	void	*init;
	int		width;
	int		height;
}	t_window;

typedef struct s_game
{
	t_position	player;
	t_position	*collectables;
	int			collected;
	int			ended;
} t_game;

enum		e_memory_actions
{
	FREE,
	PUSH
};

/******************************************************************************\
* SO_LONG																	   *
\******************************************************************************/

void		so_long();
void		move_player_manager(int pressed_key);

/******************************************************************************\
* EVENTS																	   *
\******************************************************************************/

int			key_press(int key, t_window *window);

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
int			check_components_number(char **map);
void		check_map(t_map map);
t_map		*m(void);
void		init_map(char **map);
void		swap_char(t_position current_position, t_position end_position);
t_position	get_player_current_position();
char		get_pos_component(t_position pos);

/******************************************************************************\
* MEMORY																       *
\******************************************************************************/

void		memory(enum e_memory_actions action, void *payload);
void		*ft_salloc(size_t size);
void		*ft_palloc(size_t size);

/******************************************************************************\
* GAME																		   *
\******************************************************************************/

t_game	*game();
void	init_game();
void	game__set_player(t_position player);

/******************************************************************************\
* UTILS																	       *
\******************************************************************************/

void		ft_free_matrix(char **matrix);
char		**ft_psplit(const char *s, char c);
char		*ft_read_file(int fd);
char		*ft_pread_file(int fd);
void		ft_mtxiteri(char **mtx, void (*f) (unsigned int, unsigned int, char *));

/******************************************************************************\
* WINDOW																	   *
\******************************************************************************/

void		init_window(int width, int height);
void		*get_image(char *filename);
void		put_image(char *img_path, t_position position);
void		load_images(char **map);
int			render(t_map *map);
t_window	*w(void);
int			close_window(t_window *window);

#endif
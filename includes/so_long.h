/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:54:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/08 02:56:47 by kmatos-s         ###   ########.fr       */
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
# define C_PLAYER 'P'
# define C_COLLECTABLE 'C'
# define C_EXIT 'E'
# define C_GROUND '0'
# define C_WALL '1'

/******************************************************************************\
* TYPES 																	   *
\******************************************************************************/

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

t_position		new_position(int x, int y);

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
	int			collectables;
	int			collected;
	int			movements;
	int			ended;
} t_game;


enum		e_memory_actions
{
	FREE,
	PUSH
};

enum		e_memory_types
{
	IMAGE,
	VOID
};

typedef struct s_memory_node
{
	void			*content;
	enum e_memory_types	type;
} t_memory_node;


/******************************************************************************\
* SO_LONG																	   *
\******************************************************************************/

void		so_long(void);
void		move_player_manager(int pressed_key);

/******************************************************************************\
* EVENTS																	   *
\******************************************************************************/

int			e__key_press(int key, t_window *window);

/******************************************************************************\
* LOGGER																	   *
\******************************************************************************/

void		logg(char *message);
void		on_error(char *error_message);
void		on_success(char *success_message);

/******************************************************************************\
* MAPPER																	   *
\******************************************************************************/

t_map		*m(void);
void		m__init(char **map);
void		m__check(t_map map);
int			m__is_player(char c);
int			m__is_collectable(char c);
int			m__is_exit(char c);
int			m__is_ground(char c);
int			m__is_wall(char c);
size_t		m__width(char **matrix);
size_t		m__height(char **matrix);
int			m__is_valid_extension(char *file_name);
int			m__check_retangular(int width, int height);
int			m__check_width(char **map, size_t width);
int			m__check_border_walls(char **map, int width, int height);
int			m__check_valid_components(char **map);
int			m__check_components_number(char **map);
t_position	m__get_player(void);
char		m__get_component(t_position pos);
int			m__get_component_amount(int (*is_valid_component) (char));
void		m__swap_char(t_position current_position, t_position end_position);
void		m__set_component(t_position position, char c);

/******************************************************************************\
* MEMORY																       *
\******************************************************************************/

void	memory(enum e_memory_actions action, t_memory_node payload);
void	new_memory(void *content, enum e_memory_types type);
void	free_memory(void);
void	*ft_salloc(size_t size);
void	*ft_palloc(size_t size);

/******************************************************************************\
* GAME																		   *
\******************************************************************************/

t_game	*game(void);
void	game__init(void);
void	game__set_player(t_position player);

/******************************************************************************\
* UTILS																	       *
\******************************************************************************/

void		ft_free_matrix(char **matrix);
char		**ft_psplit(const char *s, char c);
char		*ft_read_file(int fd);
char		*ft_pread_file(int fd);
void		ft_mtxiteri(char **mtx, void (*f) (unsigned int, unsigned int, char *));
char		**ft_mtxcpy(char **map)
void		ft_exit(int status);

/******************************************************************************\
* WINDOW																	   *
\******************************************************************************/

t_window	*w(void);
void		w__init(int width, int height);
int			w__close(t_window *window);
void		*w__get_image(char *filename);
void		w__put_image(void	*img, t_position position);
int			w__render(t_map *map);

#endif
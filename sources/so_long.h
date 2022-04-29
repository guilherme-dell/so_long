/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:53:22 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 01:12:47 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// mlx include and X11 keycodes
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

// include open, read and close
# include <unistd.h>
# include <fcntl.h>

// include 42 libs
# include "../libs/gnl/get_next_line.h"
# include "../libs/ft_printf/ft_printf.h"

// teminal colors
# define BLUE		"\033[0;34m"
# define GREEN		"\033[0;32m"
# define RED 		"\033[1;31m"
# define GREY 		"\033[0;90m"
# define RESET 		"\033[0m"

// game font colors
# define YELLOW 	0xF7FF00

// game defines
# define TITLE "CATACOMBS"
# define PIXEL 32

// keycodes
# define KEY_SPACE 32
# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP  	65362
# define KEY_LEFT  	65361
# define KEY_RIGHT 	65363
# define KEY_DOWN  	65364

// define map assets
# define PLAYER 	'P'
# define KEYS		'C'
# define WALL		'1'
# define FLOOR		'0'
# define MAP_EXIT	'E'
# define EXIT_OPEN	'e'

// STRUCTS
typedef struct s_image
{
	void	*ptr;
	char	*pxl;
	char	*path;
	int		bpp;
	int		l_size;
	int		endian;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char	**map_lines;
	char	*map_full;
	int		columns;
	int		number_lines;
	int		keys;
	int		player;
	int		enemys;
	int		exit;
	int		player_position;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_image		wall;
	t_image		floor;
	t_image		player;
	t_image		key;
	t_image		exit;
	t_image		player_dead;
	t_image		enemy;
	t_image		door_open;
	t_map		map;
	int			moves;
	char		*text;

}	t_game;

//	PROTOTYPES

t_image	ft_new_sprite(void *mlx, char *img_path, t_game *game);
void	ft_verify_map_extension(int argc, char **argv, t_game *game);
void	ft_init_map(char	*argv, t_game *game);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strnstr(const char *str, const char *target, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
void	ft_printing(t_game *game);
void	ft_last_location(t_game	*game);
void	walk_w(t_game *game);
void	walk_a(t_game *game);
void	walk_s(t_game *game);
void	walk_d(t_game *game);
int		ft_count_lines(char	*map);
void	ft_check_map_lines(t_game *game);
void	ft_check_map_wall(t_game *game);
void	ft_init_game(t_game *game);
void	ft_valid_map_parameters(t_game *game);
void	ft_init_map_args(t_game *game);
void	ft_free_string_array(char **free_me);
void	ft_draw_map(t_game *game);
void	ft_create_paths(t_game *game);
void	ft_create_sprites(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);
void	ft_destroy_all(t_game *game);
void	ft_data_map(t_game *game, char *map_full);
void	ft_put_image(t_game *game, char type, int y, int x);
void	ft_init_all(t_game *game, int argc, char **argv);
void	ft_print_moves(t_game *game);
char	*ft_itoa(int n);
int		handle_keypress(int keysym, t_game *game);
int		handle_no_event(void);
int		ft_redraw(t_game *game);
int		close_game(t_game *game);
int		ft_error_msg(t_game *game, char	*message);
void	ft_open_door(t_game *game, int keys);

#endif
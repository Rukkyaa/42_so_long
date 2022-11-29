/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:02 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 15:52:30 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../printf/ft_printf.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx/mlx.h"
# include <time.h>

# define WIDTH 1200
# define HEIGTH 720

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115

/* IMAGES PATHS */
# define DINO_RIGHT_PATH "mandatory/images/dinoright48.xpm"
# define DINO_LEFT_PATH "mandatory/images/dinoleft48.xpm"
# define DINO_DOOR_PATH "mandatory/images/dino_door48.xpm"
# define DINO_START_PATH "mandatory/images/dinostart48.xpm"
# define WALL_PATH "mandatory/images/wall48.xpm"
# define GRASS_PATH "mandatory/images/grass48.xpm"
# define CAKE_PATH "mandatory/images/strawberrygrass_48.xpm"
# define EXIT_PATH "mandatory/images/trap48.xpm"
# define START_PATH "mandatory/images/start48.xpm"
# define WATER_PATH "mandatory/images/water48.xpm"

/* IMAGES INDEX */
# define DINO_RIGHT_INDEX 0
# define DINO_LEFT_INDEX 1
# define DINO_DOOR_INDEX 2
# define DINO_START_INDEX 3
# define WALL_INDEX 4
# define GRASS_INDEX 5
# define CAKE_INDEX 6
# define EXIT_INDEX 7
# define START_INDEX 8
# define WATER_INDEX 9

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_image
{
	void	*dinoright_img;
	void	*dinoleft_img;
	void	*dino_door_img;
	void	*dino_start_img;
	void	*wall_img;
	void	*cake_img;
	void	*grass_img;
	void	*exit_img;
	void	*start_img;
	void	*water_img;
}				t_image;

typedef struct s_player
{
	char	current;
	char	*pos;
	int		x;
	int		y;
	int		move;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	int			img_size;
	int			item_inond;
	int			item_total;
	int			items;
	t_player	player;
	t_point		start;
	t_point		end;
	void		*texture[10];
}				t_game;

char	**ft_split(char *s, char c);
char	**fd_to_map(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
bool	check_size(char **map);
bool	valid_content(char **map);
void	free_array(char **map);
char	*ft_itoa(int n);

// MAPS
char	**get_map(char *arg);
char	**dup_map(char **map);
int		get_height(char **split);
int		inondation(t_game *game);
int		valid_name(char *arg);
void	map_init(t_game *game);
void	fill_voisin(t_game *game, char **map, int x, int y);
bool	ft_check_wall(char *map, int len);

// MOVES
void	move(t_game *game, char *direction);
void	edit_pos(t_game *game, char *direction);
char	get_next(t_game *game, char *direction);
int		close_window(t_game *game);

// MLX
void	var_init(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	put_img(t_game *game, void *image, int x, int y);
void	put_dino(t_game *game, int x, int y);
void	item_collect(t_game *game);
int		key_gestion(int keycode, t_game *game);

// Error
void	ft_error(int flag);

// Animation
void	img_init(t_game *game);

#endif

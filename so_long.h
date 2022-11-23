/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:02 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/23 11:21:58 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

# define WIDTH 1200
# define HEIGTH 720

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115

/* IMAGES PATHS */
# define DINO_RIGHT_PATH "./images/dinoright48.xpm"
# define DINO_LEFT_PATH "./images/dinoleft48.xpm"
# define DINO_DOOR_PATH "./images/dino_door48.xpm"
# define DINO_START_PATH "./images/dinostart48.xpm"
# define WALL_PATH "./images/wall48.xpm"
# define GRASS_PATH "./images/grass48.xpm"
# define CAKE_PATH "./images/strawberrygrass_48.xpm"
# define EXIT_PATH "./images/trap48.xpm"
# define START_PATH "./images/start48.xpm"
# define WATER_PATH "./images/water48.xpm"

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

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_heigth;
	int		img_width;
	int		x;
	int		y;
	int		item_inond;
	int		item_total;
	int		items;
	int		move;
	char	*pos;
	t_point	start;
	t_point	end;
	void	*texture[10];
}				t_vars;

char	**ft_split(char *s, char c);
char	**fd_to_map(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
bool	check_size(char **map);
bool	valid_content(char **map);
void	free_array(char **map);

// MAPS
char	**get_map(char *arg);
char	**dup_map(char **map);
int		get_height(char **split);
int		inondation(t_vars *vars);
int		valid_name(char *arg);
void	map_init(t_vars *vars);
void	fill_voisin(t_vars *vars, char **map, int x, int y);

// HOOK
void	up(t_vars *vars);
void	down(t_vars *vars);
void	left(t_vars *vars);
void	right(t_vars *vars);
int		close_window(t_vars *vars);

// MLX
void	var_init(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	put_img(t_vars *vars, void *image, int x, int y);
void	put_dino(t_vars *vars, int x, int y);
void	item_collect(t_vars *vars);
int		key_gestion(int keycode, t_vars *vars);

// Error
void	ft_error(int flag);
#endif

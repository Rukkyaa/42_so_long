/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:02 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/22 17:20:46 by axlamber         ###   ########.fr       */
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
# define DINO_RIGHT "./images/dinoright48.xpm"
# define DINO_LEFT "./images/dinoleft48.xpm"
# define DINO_DOOR "./images/dino_door48.xpm"
# define DINO_START "./images/dinostart48.xpm"
# define WALL "./images/wall48.xpm"
# define GRASS "./images/grass48.xpm"
# define CAKE "./images/strawberrygrass_48.xpm"
# define EXIT "./images/trap48.xpm"
# define START "./images/start48.xpm"
# define WATER "./images/water48.xpm"

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
	char	*pos;
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
	t_point	start;
	t_point	end;
	t_image	image;
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
int		inondation(t_vars *vars);
void	map_init(t_vars *vars);

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
int		key_gestion(int keycode, t_vars *vars);

#endif

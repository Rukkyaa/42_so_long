/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:02 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/18 18:10:19 by axlamber         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 1280
# define HEIGTH 720

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
# define DINO "./images/dino48.xpm"
# define WALL "./images/wall48.xpm"

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
	int		dino_heigth;
	int		dino_width;
	int		x;
	int		y;
}				t_vars;

char	**ft_split(char *s, char c);
char	**fd_to_map(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
bool	check_size(char **map);
bool	valid_content(char **map);
void	free_array(char **map);

#endif

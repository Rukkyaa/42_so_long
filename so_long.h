/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:02 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/15 13:14:55 by axlamber         ###   ########.fr       */
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

char	**ft_split(char *s, char c);
char	**fd_to_map(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
bool	check_size(char **map);
bool	valid_content(char **map);
void	free_array(char **map);

#endif

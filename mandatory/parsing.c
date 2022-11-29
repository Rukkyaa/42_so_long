/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:38:14 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 15:03:00 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**string_to_map(char *s)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_split(s, '\n');
	free(s);
	if (!array)
		return (NULL);
	return (array);
}

char	**fd_to_map(int fd)
{
	ssize_t	len_read;
	char	*str;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	str = (char *)malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	len_read = 1;
	while (len_read)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		if (len_read == -1)
		{
			free(str);
			return (NULL);
		}
		buffer[len_read] = '\0';
		str = ft_strjoin_free(str, buffer);
	}
	free(buffer);
	return (string_to_map(str));
}

bool	check_size(char **map)
{
	ssize_t			i;
	ssize_t			first_line_len;

	i = -1;
	first_line_len = ft_strlen(map[0]);
	if (!ft_check_wall(map[0], first_line_len))
		return (false);
	while (map[++i])
	{
		if ((ssize_t)ft_strlen(map[i]) != first_line_len)
			return (false);
		if (map[i][0] != '1' || map[i][first_line_len - 1] != '1')
			return (false);
	}
	if (i > 0 && !ft_check_wall(map[i - 1], first_line_len))
		return (false);
	return (true);
}

void	free_array(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

bool	valid_content(char **map)
{
	bool	exit;
	bool	start;
	ssize_t	i;
	ssize_t	j;

	exit = false;
	start = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
			{
				if ((map[i][j] == 'E' && exit) || (map[i][j] == 'P' && start))
					return (false);
				else if (map[i][j] == 'E')
					exit = true;
				else if (map[i][j] == 'P')
					start = true;
			}
		}
	}
	return (start && exit);
}

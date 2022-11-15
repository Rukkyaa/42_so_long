/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:57:46 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/15 13:17:35 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**map;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (EXIT_FAILURE);
	map = fd_to_map(fd);
	if (!map)
		return (EXIT_FAILURE);
	i = 0;
	printf("content : %d\n", valid_content(map));
	if (!check_size(map) || !valid_content(map))
	{
		free_array(map);
		return (EXIT_FAILURE);
	}
	printf("size : %d\n", check_size(map));
	while (map[i])
		printf("%s\n", map[i ++]);
	free_array(map);
	return (EXIT_SUCCESS);
}

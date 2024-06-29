/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:58:55 by snourry           #+#    #+#             */
/*   Updated: 2023/01/28 12:46:01 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_size(t_map *map, t_cube *cube);

/**
 * @brief Function is used to parse the map.
 * 
 * @param line First line of map.
 * @param fd File Descriptor of map file.
 * @param cube Is main parsing struct.
 * @return true If map is correct.
 * @return false If map isn't correct.
 */
bool	map(char *line, int fd, t_cube *cube)
{
	t_map	*map;

	map = NULL;
	if (cube->map)
		return (false);
	map = add_map(map, line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = add_map(map, line);
	}
	map = first_map(map);
	init_size(map, cube);
	map = first_map(map);
	cube->map = map_2d(map, cube);
	return (true);
}

/**
 * @brief Function is used to define size of map.
 */
static void	init_size(t_map *map, t_cube *cube)
{
	size_t	size;

	while (map)
	{
		cube->height++;
		size = ft_strlen(map->line);
		if (map->line[size - 1] == '\n')
			size--;
		if (size > cube->width)
			cube->width = size;
		map = map->next;
	}
}

/**
 * @brief Function to check spawn.
 * 
 * @return true if have spawn.
 * @return false if don't have spawn. 
 */
bool	check_spawn(const char *filename, t_cube *cube)
{
	(void) filename;
	if (cube->pos_x < 0)
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:20:18 by snourry           #+#    #+#             */
/*   Updated: 2022/12/14 22:55:54 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Function is used to add line of map.
 */
t_map	*add_map(t_map *map, char *line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
	{
		error(ERROR_ALLOC);
		return (false);
	}
	map = last_map(map);
	if (map)
		map->next = new;
	new->prev = map;
	new->next = NULL;
	new->line = line;
	return (new);
}

/**
 * @brief Function is used to get last map;
 */
t_map	*last_map(t_map *map)
{
	while (map)
	{
		if (!map->next)
			return (map);
		map = map->next;
	}
	return (NULL);
}

/**
 * @brief Function is used to get first map;
 */
t_map	*first_map(t_map *map)
{
	while (map)
	{
		if (!map->prev)
			return (map);
		map = map->prev;
	}
	return (NULL);
}

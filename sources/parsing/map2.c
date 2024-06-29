/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:37:25 by snourry           #+#    #+#             */
/*   Updated: 2023/01/28 12:43:18 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_alloc_failed(char **smap, int i);
static void	linecpy(char *str, const char *src, size_t len);
static void	free_map(t_map *map);

/**
 * @brief Function is used to convert map list to map (char **).
 */
char	**map_2d(t_map *map, t_cube *cube)
{
	char	**smap;
	size_t	i;

	smap = malloc(sizeof(char *) * (cube->height + 1));
	if (!smap)
	{
		error(ERROR_ALLOC);
		return (NULL);
	}
	i = -1;
	while (++i < cube->height)
	{
		smap[i] = malloc(sizeof(char) * (cube->width + 1));
		if (!smap[i])
		{
			free_alloc_failed(smap, i - 1);
			return (NULL);
		}
		linecpy(smap[i], map->line, cube->width);
		if (map->next)
			map = map->next;
	}
	smap[i] = NULL;
	free_map(map);
	return (smap);
}

static void	free_alloc_failed(char **smap, int i)
{
	error(ERROR_ALLOC);
	while (i >= 0)
	{
		free(smap[i]);
		smap[i] = NULL;
		i--;
	}
	free(smap);
	smap = NULL;
}

static void	linecpy(char *str, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[len] = 0;
}

static void	free_map(t_map *map)
{
	t_map	*tmp;

	map = last_map(map);
	while (map)
	{
		tmp = map;
		map = map->prev;
		if (tmp->prev)
			free(tmp->line);
		tmp->line = NULL;
		free(tmp);
		tmp = NULL;
	}
}

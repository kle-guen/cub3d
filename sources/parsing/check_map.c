/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:00:27 by snourry           #+#    #+#             */
/*   Updated: 2023/02/01 13:09:21 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_border(t_cube *cube);
static bool	check_map_void_line(t_cube *cube);
static bool	check_map_char(t_cube *cube, const char c, size_t i, size_t j);
static bool	init_spawn(t_cube *cube, const char c, size_t i, size_t j);

/**
 * @brief Function to check the map.
 * 
 * @return true if map is correct.
 * @return false if map isn't correct.
 */
bool	check_map(const char *filename, t_cube *cube)
{
	size_t	i;
	size_t	j;

	(void) filename;
	if (!check_map_border(cube))
		return (false);
	if (!check_map_void_line(cube))
		return (false);
	i = 0;
	while (i < cube->height)
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (!check_map_char(cube, cube->map[i][j], i, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * @brief Function is used to check border of map.
 */
static bool	check_map_border(t_cube *cube)
{
	size_t	i;

	i = 0;
	while (cube->map[0][i])
	{
		if (cube->map[0][i] != ' ' && cube->map[0][i] != '1')
			return (false);
		if (cube->map[cube->height - 1][i] != ' ' && \
		cube->map[cube->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < cube->height)
	{
		if (cube->map[i][0] != ' ' && cube->map[i][0] != '1')
			return (false);
		if (cube->map[i][cube->width - 1] != ' ' && \
		cube->map[i][cube->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Function is used to check void line map.
 */
static bool	check_map_void_line(t_cube *cube)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cube->height)
	{
		j = 0;
		while (cube->map[i][j] && (cube->map[i][j] == 32 || \
		(cube->map[i][j] >= 9 && cube->map[i][j] <= 13)))
			j++;
		if (!cube->map[i][j])
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Function is used to check void line map.
 */
static bool	check_map_char(t_cube *cube, const char c, size_t i, size_t j)
{
	if (c == '0' || c == '1')
		return (true);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (init_spawn(cube, c, i, j));
	else if (c == ' ')
	{
		if (i != 0 && cube->map[i - 1][j] != ' ' && cube->map[i - 1][j] != '1')
			return (false);
		if (i != (cube->height - 1) && cube->map[i + 1][j] != ' ' && \
		cube->map[i + 1][j] != '1')
			return (false);
		if (j != 0 && cube->map[i][j - 1] != ' ' && cube->map[i][j - 1] != '1')
			return (false);
		if (j != (cube->width - 1) && cube->map[i][j + 1] != ' ' && \
		cube->map[i][j + 1] != '1')
			return (false);
		return (true);
	}
	return (false);
}

/**
 * @brief Function is used to init spawn position.
 */
static bool	init_spawn(t_cube *cube, const char c, size_t i, size_t j)
{
	if (cube->pos_x != -1)
		return (false);
	cube->map[i][j] = '0';
	cube->direction = c;
	cube->pos_x = j + 0.5;
	cube->pos_y = i + 0.5;
	return (true);
}

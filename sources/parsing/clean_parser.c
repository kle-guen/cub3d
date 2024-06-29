/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:42:42 by snourry           #+#    #+#             */
/*   Updated: 2023/01/18 04:23:31 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_texture(t_cube *cube);
static void	clean_map(t_cube *cube);

/**
 * @brief Function to clean cube parsing if file isn't correct.
 * 
 * @param cube Variable to clean.
 */
void	clean(t_cube *cube)
{
	clean_texture(cube);
	if (cube->map)
		clean_map(cube);
	mlx_destroy_display(cube->mlx);
	free(cube->mlx);
	cube->mlx = NULL;
	free(cube);
	cube = NULL;
}

static void	clean_texture(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cube->texture[i].img)
			mlx_destroy_image(cube->mlx, cube->texture[i].img);
		i++;
	}
}

static void	clean_map(t_cube *cube)
{
	size_t	i;

	i = 0;
	while (i < cube->height)
	{
		if (cube->map[i])
			free(cube->map[i]);
		cube->map[i] = NULL;
		i++;
	}
	free(cube->map);
	cube->map = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:52:17 by snourry           #+#    #+#             */
/*   Updated: 2023/01/20 11:38:32 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/**
 * @brief Function is used to draw square.
 */
void	draw_square(t_cube *cube, int color, int x, int y)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			pixel = ((y + j) * 300 + (x + i)) * 4;
			cube->minimap[pixel + 3 - (3 * cube->endian)] = (color >> 24);
			cube->minimap[pixel + 2 - cube->endian] = (color >> 16) & 0xFF;
			cube->minimap[pixel + 1 + cube->endian] = (color >> 8) & 0xFF;
			cube->minimap[pixel + (3 * cube->endian)] = (color) & 0xFF;
			j++;
		}
		i++;
	}
}

static void	draw_wall2(t_cube *cube, int i, int j)
{
	if (cube->map[(int)cube->pos_y + j][(int)cube->pos_x + i] == '0')
		draw_square(cube, 0xFFFFFF, (i + 7) * 20, (j + 7) * 20);
	else if (cube->map[(int)cube->pos_y + j][(int)cube->pos_x + i] == '1')
		draw_square(cube, 0x7F7F7F, (i + 7) * 20, (j + 7) * 20);
	else if (cube->map[(int)cube->pos_y + j][(int)cube->pos_x + i] == '2')
		draw_square(cube, 0xFF0000, (i + 7) * 20, (j + 7) * 20);
	else if (cube->map[(int)cube->pos_y + j][(int)cube->pos_x + i] == '3')
		draw_square(cube, 0x00FF00, (i + 7) * 20, (j + 7) * 20);
}

/**
 * @brief Function is used to draw wall of minimap.
 */
void	draw_wall(t_cube *cube)
{
	int	i;
	int	j;

	i = -6;
	while (i < 7)
	{
		j = -6;
		while (j < 7)
		{
			if ((int)cube->pos_x + i >= 0 && (int)cube->pos_y + j >= 0 && \
			(int)cube->pos_x + i < (int)cube->width && \
			(int)cube->pos_y + j < (int)cube->height)
				draw_wall2(cube, i, j);
			j++;
		}
		i++;
	}
}

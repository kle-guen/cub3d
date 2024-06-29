/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:51:19 by snourry           #+#    #+#             */
/*   Updated: 2023/01/20 15:32:26 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>
#include <time.h>

#define SPEED 5

typedef struct s_outline
{
	int	i;
	int	j;
}		t_outline;

static void	draw_random_outline(t_cube *cube);
static void	draw_outline(t_cube *cube, t_texture texture, int color);
static void	draw_pixel(t_cube *cube, t_texture texture, int color, \
t_outline outline);

int	draw_anim(void *var)
{
	static int	i = 0;
	t_cube		*cube;

	cube = (t_cube *)var;
	if (i < SPEED)
		draw_random_outline(cube);
	else
		i = 0;
	i++;
	return (0);
}

/**
 * @brief Function is used to draw a random color outline at all textures.
 */
static void	draw_random_outline(t_cube *cube)
{
	int	color;
	int	i;

	srand(time(NULL));
	color = rand();
	i = 0;
	while (i < 4)
	{
		draw_outline(cube, cube->texture[i], color);
		i++;
	}
	mlx_destroy_image(cube->mlx, cube->img1);
	cube->img1 = mlx_new_image(cube->mlx, WIN_SX, WIN_SY);
	cube->background = mlx_get_data_addr(cube->img1, &cube->pixel_bits, \
	&cube->line_bytes, &cube->endian);
	put_background_color(cube);
	launch_raycasting(cube->vector_tab, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img1, 0, 0);
	show_minimap(cube);
}

static void	draw_outline(t_cube *cube, t_texture texture, int color)
{
	t_outline	outline;
	int			size;

	outline.i = 0;
	size = texture.h / 10;
	if (texture.w != texture.h)
		return ;
	while (outline.i < texture.w)
	{
		outline.j = 0;
		while (outline.j < texture.w)
		{
			if (outline.i < size || outline.i > texture.w - size \
			|| outline.j < size || outline.j > texture.w - size)
				draw_pixel(cube, texture, color, outline);
			outline.j++;
		}
		outline.i++;
	}
}

static void	draw_pixel(t_cube *cube, t_texture texture, int color, \
t_outline outline)
{
	int	pixel;

	pixel = (outline.j * texture.w + outline.i) * 4;
	texture.buff[pixel + 3 - (3 * cube->endian)] = (color >> 24);
	texture.buff[pixel + 2 - cube->endian] = (color >> 16) & 0xFF;
	texture.buff[pixel + 1 + cube->endian] = (color >> 8) & 0xFF;
	texture.buff[pixel + (3 * cube->endian)] = (color) & 0xFF;
}

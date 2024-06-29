/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:02:42 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/19 14:13:44 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_background_color(t_cube *var)
{
	t_color	color;
	int		pixel;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WIN_SY)
	{
		while (x < WIN_SX)
		{
			pixel = (y * WIN_SX + x) * 4;
			if (y < WIN_SY / 2)
				color = var->ceiling;
			else
				color = var->floor;
			var->background[pixel + 2 - var->endian] = color.red;
			var->background[pixel + 1 + var->endian] = color.green;
			var->background[pixel + 3 * var->endian] = color.blue;
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_vertical_line(t_cube *var, int x, int y0, int y1)
{
	int	y;
	int	pixel;
	int	text_pixel;
	int	text_y;

	y = y0;
	while (y < y1)
	{
		text_y = (int)var->texture[var->text_nb].pos;
		pixel = (y * WIN_SX + x) * 4;
		text_pixel = (var->texture[var->text_nb].w * text_y + \
		var->texture[var->text_nb].x) * 4;
		var->texture[var->text_nb].pos += var->texture[var->text_nb].step;
		if (text_y < var->texture[var->text_nb].h && \
		var->texture[var->text_nb].x < var->texture[var->text_nb].w)
		{
			var->background[pixel + 2] = \
			var->texture[var->text_nb].buff[text_pixel + 2];
			var->background[pixel + 1] = \
			var->texture[var->text_nb].buff[text_pixel + 1];
			var->background[pixel + 0] = \
			var->texture[var->text_nb].buff[text_pixel + 0];
		}
		y++;
	}
}

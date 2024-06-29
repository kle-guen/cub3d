/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:58:07 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/20 11:20:04 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	left(t_cube *var)
{
	double	x_step;
	double	y_step;

	x_step = STEP * (cos(M_PI_2) * var->vector_tab[WIN_SX / 2].x - \
	sin(M_PI_2) * var->vector_tab[WIN_SX / 2].y);
	y_step = STEP * (sin(M_PI_2) * var->vector_tab[WIN_SX / 2].x + \
	cos(M_PI_2) * var->vector_tab[WIN_SX / 2].y);
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	if (var->map[(int)(var->pos_y)][(int)(var->pos_x - x_step * 2)] == '0' || \
	var->map[(int)(var->pos_y)][(int)(var->pos_x - x_step * 2)] == '3')
		var->pos_x -= x_step;
	if (var->map[(int)(var->pos_y - y_step * 2)][(int)(var->pos_x)] == '0' || \
	var->map[(int)(var->pos_y - y_step * 2)][(int)(var->pos_x)] == '3')
		var->pos_y -= y_step;
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

void	right(t_cube *var)
{
	double	x_step;
	double	y_step;

	x_step = STEP * (cos(M_PI_2) * var->vector_tab[WIN_SX / 2].x - \
	sin(M_PI_2) * var->vector_tab[WIN_SX / 2].y);
	y_step = STEP * (sin(M_PI_2) * var->vector_tab[WIN_SX / 2].x + \
	cos(M_PI_2) * var->vector_tab[WIN_SX / 2].y);
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	if (var->map[(int)(var->pos_y)][(int)(var->pos_x + x_step * 2)] == '0' || \
	var->map[(int)(var->pos_y)][(int)(var->pos_x + x_step * 2)] == '3')
		var->pos_x += x_step;
	if (var->map[(int)(var->pos_y + y_step * 2)][(int)(var->pos_x)] == '0' || \
	var->map[(int)(var->pos_y + y_step * 2)][(int)(var->pos_x)] == '3')
		var->pos_y += y_step;
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

void	forward(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	if (var->map[(int)(var->pos_y)][(int)(var->pos_x + var->vector_tab \
	[WIN_SX / 2].x * STEP * 2)] == '0' || var->map[(int)(var->pos_y)] \
	[(int)(var->pos_x + var->vector_tab[WIN_SX / 2].x * STEP * 2)] == '3')
		var->pos_x += var->vector_tab[WIN_SX / 2].x * STEP;
	if (var->map[(int)(var->pos_y + var->vector_tab[WIN_SX / 2].y * STEP * 2)] \
	[(int)(var->pos_x)] == '0' || var->map[(int)(var->pos_y + \
	var->vector_tab[WIN_SX / 2].y * STEP * 2)][(int)(var->pos_x)] == '3')
		var->pos_y += var->vector_tab[WIN_SX / 2].y * STEP;
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

void	back(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	if (var->map[(int)(var->pos_y)] \
	[(int)(var->pos_x - var->vector_tab[WIN_SX / 2].x * STEP * 2)] == '0' || \
	var->map[(int)(var->pos_y)] \
	[(int)(var->pos_x - var->vector_tab[WIN_SX / 2].x * STEP * 2)] == '3')
		var->pos_x -= var->vector_tab[WIN_SX / 2].x * STEP;
	if (var->map[(int)(var->pos_y - var->vector_tab[WIN_SX / 2].y * STEP * 2)] \
	[(int)(var->pos_x)] == '0' || var->map[(int)(var->pos_y - \
	var->vector_tab[WIN_SX / 2].y * STEP * 2)][(int)(var->pos_x)] == '3')
		var->pos_y -= var->vector_tab[WIN_SX / 2].y * STEP;
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:37:18 by snourry           #+#    #+#             */
/*   Updated: 2023/01/20 15:13:53 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	left(t_cube *var);
void	right(t_cube *var);
void	forward(t_cube *var);
void	back(t_cube *var);

int	exit_hook(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	mlx_destroy_image(var->mlx, var->img2);
	mlx_destroy_window(var->mlx, var->win);
	free(var->vector_tab);
	var->vector_tab = NULL;
	clean(var);
	exit(0);
}

void	rotate_right(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	var->angle += M_PI / 12;
	rotate_vectors(var->vector_tab, (M_PI / 12));
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

void	rotate_left(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	var->angle -= M_PI / 12;
	rotate_vectors(var->vector_tab, -(M_PI / 12));
	put_background_color(var);
	launch_raycasting(var->vector_tab, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
	show_minimap(var);
}

static void	door(t_cube *cube)
{
	if (cube->map[(int)cube->pos_y + 1][(int)cube->pos_x] == '2')
		cube->map[(int)cube->pos_y + 1][(int)cube->pos_x] = '3';
	else if (cube->map[(int)cube->pos_y + 1][(int)cube->pos_x] == '3')
		cube->map[(int)cube->pos_y + 1][(int)cube->pos_x] = '2';
	if (cube->map[(int)cube->pos_y - 1][(int)cube->pos_x] == '2')
		cube->map[(int)cube->pos_y - 1][(int)cube->pos_x] = '3';
	else if (cube->map[(int)cube->pos_y - 1][(int)cube->pos_x] == '3')
		cube->map[(int)cube->pos_y - 1][(int)cube->pos_x] = '2';
	if (cube->map[(int)cube->pos_y][(int)cube->pos_x + 1] == '2')
		cube->map[(int)cube->pos_y][(int)cube->pos_x + 1] = '3';
	else if (cube->map[(int)cube->pos_y][(int)cube->pos_x + 1] == '3')
		cube->map[(int)cube->pos_y][(int)cube->pos_x + 1] = '2';
	if (cube->map[(int)cube->pos_y][(int)cube->pos_x - 1] == '2')
		cube->map[(int)cube->pos_y][(int)cube->pos_x - 1] = '3';
	else if (cube->map[(int)cube->pos_y][(int)cube->pos_x - 1] == '3')
		cube->map[(int)cube->pos_y][(int)cube->pos_x - 1] = '2';
	mlx_destroy_image(cube->mlx, cube->img1);
	cube->img1 = mlx_new_image(cube->mlx, WIN_SX, WIN_SY);
	cube->background = mlx_get_data_addr(cube->img1, &cube->pixel_bits, \
	&cube->line_bytes, &cube->endian);
	put_background_color(cube);
	launch_raycasting(cube->vector_tab, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img1, 0, 0);
	show_minimap(cube);
}

int	key_win(int key, t_cube *var)
{
	if (key == XK_Escape)
		exit_hook(var);
	else if (key == XK_w)
		forward(var);
	else if (key == XK_s)
		back(var);
	else if (key == XK_d)
		right(var);
	else if (key == XK_a)
		left(var);
	else if (key == XK_Left)
		rotate_left(var);
	else if (key == XK_Right)
		rotate_right(var);
	else if (key == XK_e)
		door(var);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:37:18 by snourry           #+#    #+#             */
/*   Updated: 2023/01/18 04:23:24 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left(t_cube *var);
void	right(t_cube *var);
void	forward(t_cube *var);
void	back(t_cube *var);

int	exit_hook(t_cube *var)
{
	mlx_destroy_image(var->mlx, var->img1);
	mlx_destroy_window(var->mlx, var->win);
	free(var->vector_tab);
	var->vector_tab = NULL;
	clean(var);
	exit(0);
}

static void	rotate_right(t_cube *var)
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
}

static void	rotate_left(t_cube *var)
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
	return (0);
}

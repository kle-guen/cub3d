/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:46:05 by snourry           #+#    #+#             */
/*   Updated: 2023/01/20 19:32:44 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = parser(argc, argv);
	if (!cube)
		return (1);
	init_vars(cube);
	init_minimap(cube);
	put_background_color(cube);
	launch_raycasting(cube->vector_tab, cube);
	mlx_hook(cube->win, KeyPress, KeyPressMask, key_win, cube);
	mlx_hook(cube->win, DestroyNotify, StructureNotifyMask, exit_hook, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img1, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img2, \
	WIN_SX - 300, WIN_SY - 300);
	mlx_loop_hook(cube->mlx, draw_anim, cube);
	mlx_hook (cube->win, 6, 1 << 6L, mouse, cube);
	mlx_mouse_hide(cube->mlx, cube->win);
	mlx_loop(cube->mlx);
	return (0);
}

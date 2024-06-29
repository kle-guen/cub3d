/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-guen <kle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:46:05 by snourry           #+#    #+#             */
/*   Updated: 2023/01/18 16:55:17 by kle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	cube = parser(argc, argv);
	if (!cube)
		return (1);
	init_vars(cube);
	put_background_color(cube);
	launch_raycasting(cube->vector_tab, cube);
	mlx_hook(cube->win, KeyPress, KeyPressMask, key_win, cube);
	mlx_hook(cube->win, DestroyNotify, StructureNotifyMask, exit_hook, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img1, 0, 0);
	mlx_loop(cube->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:30:19 by snourry           #+#    #+#             */
/*   Updated: 2023/01/20 13:00:20 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		draw_square(t_cube *cube, int color, int x, int y);
void		draw_wall(t_cube *cube);

/**
 * @brief Function is used to init minimap.
 */
void	init_minimap(t_cube *cube)
{
	cube->img2 = mlx_new_image(cube->mlx, 300, 300);
	cube->minimap = mlx_get_data_addr(cube->img2, \
		&cube->pixel_bits, &cube->line_bytes, &cube->endian);
	draw_wall(cube);
	draw_square(cube, 0x0000FF, 140, 140);
}

/**
 * @brief Function is used to show minimap.
 */
void	show_minimap(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->img2);
	init_minimap(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, \
	cube->img2, WIN_SX - 300, WIN_SY - 300);
}

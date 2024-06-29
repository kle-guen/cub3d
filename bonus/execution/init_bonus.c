/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:59:44 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/20 12:14:35 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_player_view(t_cube *var)
{
	if (var->direction == 'S')
		rotate_vectors(var->vector_tab, (M_PI));
	if (var->direction == 'W')
		rotate_vectors(var->vector_tab, (M_PI_2));
	if (var->direction == 'E')
		rotate_vectors(var->vector_tab, (-M_PI_2));
}

static t_vector	*init_vector_tab(void)
{
	int			i;
	t_vector	*tab;
	double		fov;
	double		rh;

	i = 0;
	fov = M_PI_2;
	rh = 2 * tan(fov / 2) / WIN_SX;
	tab = malloc(sizeof(t_vector) * (WIN_SX + 1));
	if (!tab)
		return (NULL);
	while (i < WIN_SX)
	{
		tab[i].x = (i - WIN_SX * 0.5) * rh;
		tab[i].y = -1.0;
		tab[i].i = i;
		i++;
	}
	return (tab);
}

void	init_vars(t_cube *var)
{
	var->text_nb = 0;
	var->win = mlx_new_window(var->mlx, WIN_SX, WIN_SY, "Cub3d");
	var->img1 = mlx_new_image(var->mlx, WIN_SX, WIN_SY);
	var->background = mlx_get_data_addr(var->img1, &var->pixel_bits, \
	&var->line_bytes, &var->endian);
	var->vector_tab = init_vector_tab();
	set_player_view(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-guen <kle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:33:10 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/28 09:45:06 by kle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_dda_vars(t_cube *var, t_dda *dda, t_vector *vect)
{
	dda->map_x = (int)var->pos_x;
	dda->map_y = (int)var->pos_y;
	dda->step_x = 0;
	dda->step_y = 0;
	dda->hit = 0;
	dda->side_dist_x = 0.0;
	dda->side_dist_y = 0.0;
	if (vect->x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = sqrt(1 + pow(vect->y, 2.0) / pow(vect->x, 2.0));
	if (vect->y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = sqrt(1 + pow(vect->x, 2.0) / pow(vect->y, 2.0));
}

void	dda_init(t_cube *var, t_vector *vect, t_dda *dda)
{
	init_dda_vars(var, dda, vect);
	if (vect->x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (var->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - var->pos_x) * dda->delta_dist_x;
	}
	if (vect->y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (var->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - var->pos_y) * dda->delta_dist_y;
	}
}

void	dda_algo(t_cube *var, t_dda *dda, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			*side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			*side = 1;
		}
		if (var->map[dda->map_y][dda->map_x] == '2')
			var->text_nb = 4;
		if (var->map[dda->map_y][dda->map_x] != '0' \
		&& var->map[dda->map_y][dda->map_x] != '3')
			hit = 1;
	}
}

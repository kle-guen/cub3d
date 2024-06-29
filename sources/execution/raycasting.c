/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-guen <kle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:16 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/28 09:44:29 by kle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_line_height(t_cube *var, t_dda *dda, int side, t_vector *vect)
{
	int	line_height;

	if (side == 0)
		var->wall_dist = (dda->map_x - var->pos_x + (1 - dda->step_x) / 2) \
		/ vect->x;
	else
		var->wall_dist = (dda->map_y - var->pos_y + (1 - dda->step_y) / 2) \
		/ vect->y;
	line_height = (int)(WIN_SY / var->wall_dist);
	return (line_height);
}

static void	find_text_x(t_cube *var, t_vector *vect, int side)
{
	if (side == 0)
		var->wall_x = var->pos_y + var->wall_dist * vect->y;
	else
		var->wall_x = var->pos_x + var->wall_dist * vect->x;
	var->wall_x -= floor(var->wall_x);
	var->texture[var->text_nb].x = (int)(var->wall_x * \
	(double)var->texture[var->text_nb].w);
	if (side == 0 && vect->x > 0)
		var->texture[var->text_nb].x = var->texture[var->text_nb].w - \
		var->texture[var->text_nb].x - 1;
	if (side == 1 && vect->y < 0)
		var->texture[var->text_nb].x = var->texture[var->text_nb].w - \
		var->texture[var->text_nb].x - 1;
}

static void	find_text_nb(t_cube *var, t_vector *vect, int side)
{
	if (side && vect->y < 0)
		var->text_nb = 1;
	else if (side && vect->y > 0)
		var->text_nb = 0;
	else if (side == 0 && vect->x > 0)
		var->text_nb = 3;
	else if (side == 0 && vect->x < 0)
		var->text_nb = 2;
}

static void	raycasting(t_cube *var, t_vector *vect)
{
	t_dda	*dda;
	int		side;
	int		line_height;
	int		y0;
	int		y1;

	dda = &var->dda;
	dda_init(var, vect, dda);
	dda_algo(var, dda, &side);
	line_height = find_line_height(var, dda, side, vect);
	y0 = (WIN_SY / 2) - (line_height / 2);
	y1 = (WIN_SY / 2) + (line_height / 2);
	if (y0 < 0)
		y0 = 0;
	if (y1 > WIN_SY)
		y1 = WIN_SY;
	find_text_nb(var, vect, side);
	find_text_x(var, vect, side);
	var->texture[var->text_nb].step = \
	(double)var->texture[var->text_nb].h / (double)line_height;
	var->texture[var->text_nb].pos = ((double)y0 - ((double)WIN_SY / 2) + \
	((double)line_height / 2)) * var->texture[var->text_nb].step;
	draw_vertical_line(var, vect->i, y0, y1);
}

void	launch_raycasting(t_vector *vector_tab, t_cube *var)
{
	int	i;

	i = 0;
	while (i < WIN_SX)
	{
		raycasting(var, &vector_tab[i]);
		i++;
	}
}

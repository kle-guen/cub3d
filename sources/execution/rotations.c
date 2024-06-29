/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:20:33 by kle-guen          #+#    #+#             */
/*   Updated: 2023/01/18 06:12:29 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_vectors(t_vector *vector_tab, double angle)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < WIN_SX)
	{
		tmp = vector_tab[i].x;
		vector_tab[i].x = cos(angle) * vector_tab[i].x \
		- sin(angle) * vector_tab[i].y;
		vector_tab[i].y = sin(angle) * tmp \
		+ cos(angle) * vector_tab[i].y;
		i++;
	}
}

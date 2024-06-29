/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:45:01 by snourry           #+#    #+#             */
/*   Updated: 2023/01/18 06:48:37 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# include "cub3d_message.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIN_SX 1600
# define WIN_SY 900
# define STEP 0.1

/**
 *		Parsing Functions
 */

t_cube	*parser(int argc, char **argv);
bool	texture(const char *flag, char *line, t_cube *cube);
bool	color(const char *flag, char *line, t_cube *cube);
bool	map(char *line, int fd, t_cube *cube);
char	**map_2d(t_map *map, t_cube *cube);
bool	parse_map(const char *filename, t_cube *cube);
bool	check_extension(const char *filename, t_cube *cube);
bool	check_name(const char *filename, t_cube *cube);
bool	check_exist(const char *filename, t_cube *cube);
bool	check_texture(const char *filename, t_cube *cube);
bool	check_color(const char *filename, t_cube *cube);
bool	check_map(const char *filename, t_cube *cube);
bool	check_spawn(const char *filename, t_cube *cube);
void	clean(t_cube *cube);

/**
 *		Execution Function
 */
int		key_win(int key, t_cube *var);
void	launch_raycasting(t_vector *vector_tab, t_cube *var);
void	put_background_color(t_cube *var);
void	rotate_vectors(t_vector *vector_tab, double angle);
void	dda_algo(t_cube *var, t_dda *dda, int *side);
void	dda_init(t_cube *var, t_vector *vect, t_dda *dda);
void	init_vars(t_cube *var);
void	draw_vertical_line(t_cube *var, int x, int y0, int y1);
int		exit_hook(t_cube *var);

/**
 *		Utils Functions
 */

void	gnl_clear(int fd);
t_map	*add_map(t_map *map, char *line);
t_map	*last_map(t_map *map);
t_map	*first_map(t_map *map);

#endif

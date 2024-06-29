/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:45:40 by snourry           #+#    #+#             */
/*   Updated: 2022/11/30 11:45:40 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_color
{
	bool			init;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct s_map
{
	struct s_map	*prev;
	struct s_map	*next;
	char			*line;
}					t_map;

typedef struct s_texture
{
	void	*img;
	char	*buff;
	int		w;
	int		h;
	int		x;
	double	pos;
	double	step;
}			t_texture;

typedef struct s_vector
{
	double	x;
	double	y;
	int		i;
}			t_vector;

typedef struct s_dda
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		hit;
}			t_dda;

typedef struct s_cube
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img1;
	char		*background;
	t_texture	texture[4];
	t_color		floor;
	t_color		ceiling;
	t_vector	*vector_tab;
	t_dda		dda;
	size_t		width;
	size_t		height;
	double		pos_x;
	double		pos_y;
	double		angle;
	double		wall_dist;
	double		wall_x;
	int			line_bytes;
	int			endian;
	int			pixel_bits;
	int			text_nb;
	char		direction;
}				t_cube;

#endif

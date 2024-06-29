/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:11:17 by snourry           #+#    #+#             */
/*   Updated: 2023/01/28 12:13:30 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_cube	*singleton_check(const char *filename, t_cube *cube);
static int		init(t_cube *cube);

/**
 * @brief Function is used to parse the file.
 * 
 * @return (t_cube *) Parsed file.
 */
t_cube	*parser(int argc, char **argv)
{
	t_cube	*cube;

	if (argc != 2)
	{
		error(ERROR_USAGE);
		return (NULL);
	}
	cube = malloc(sizeof(t_cube));
	if (!cube)
	{
		error(ERROR_ALLOC);
		return (NULL);
	}
	if (init(cube) == -1)
	{
		ft_putstr_fd("Nice try ! c:\n", 2);
		free(cube);
		return (NULL);
	}
	cube = singleton_check((const char *)argv[1], cube);
	return (cube);
}

/**
 * @brief Struct for create a Singleton.
 */
typedef struct s_parse
{
	bool		((*f)(const char *, t_cube *));
	t_message	message;
}				t_parse;

/**
 * @brief Function is used to check all parsing error with a singleton.
 * 
 * @return (t_cube *) Valid if there are no errors.
 */
static t_cube	*singleton_check(const char *filename, t_cube *cube)
{
	int						i;
	static const t_parse	parse[] = {
	{&check_extension, ERROR_EXTENSION},
	{&check_name, ERROR_NAME},
	{&check_exist, ERROR_EXIST},
	{&parse_map, ERROR_READ},
	{&check_texture, ERROR_TEXTURE},
	{&check_color, ERROR_COLOR},
	{&check_map, ERROR_MAP},
	{&check_spawn, ERROR_SPAWN}};

	i = 0;
	while (i < 8)
	{
		if (!parse[i].f(filename, cube))
		{
			error(parse[i].message);
			clean(cube);
			return (NULL);
		}
		i++;
	}
	return (cube);
}

/**
 * @brief Function is used to initialize values of cube.
 */
static int	init(t_cube *cube)
{
	int	i;

	cube->mlx = mlx_init();
	if (!cube->mlx)
		return (-1);
	cube->win = NULL;
	cube->map = NULL;
	i = 0;
	while (i < 4)
		cube->texture[i++].img = NULL;
	cube->floor.init = false;
	cube->ceiling.init = false;
	cube->height = 0;
	cube->width = 0;
	cube->pos_x = -1;
	return (0);
}

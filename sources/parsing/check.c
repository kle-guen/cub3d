/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:20:49 by snourry           #+#    #+#             */
/*   Updated: 2023/01/16 16:08:07 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Function to check extension of file.
 * 
 * @return true if file is a .cub.
 * @return false if file isn't a .cub.
 */
bool	check_extension(const char *filename, t_cube *cube)
{
	size_t	length;

	(void) cube;
	length = ft_strlen(filename);
	if (length < 4)
		return (false);
	if (ft_strcmp(&filename[length - 4], ".cub") != 0)
		return (false);
	return (true);
}

/**
 * @brief Function to check name of file.
 * 
 * @return true if file name is correct.
 * @return false if file name isn't correct. 
 */
bool	check_name(const char *filename, t_cube *cube)
{
	(void) cube;
	if (ft_strlen(filename) < 5)
		return (false);
	if (ft_strrchr(filename, '/') && ft_strlen(ft_strrchr(filename, '/')) < 6)
		return (false);
	return (true);
}

/**
 * @brief Function to check file exist.
 * 
 * @return true if file exist.
 * @return false if file don't exist. 
 */
bool	check_exist(const char *filename, t_cube *cube)
{
	int	fd;

	(void) cube;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

/**
 * @brief Function to check textures.
 * 
 * @return true if have 4 textures.
 * @return false if don't have 4 textures. 
 */
bool	check_texture(const char *filename, t_cube *cube)
{
	int	i;

	(void) filename;
	i = 0;
	while (i < 4)
	{
		if (!cube->texture[i].img)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Function to check colors.
 * 
 * @return true if have 2 colors.
 * @return false if don't have 2 colors. 
 */
bool	check_color(const char *filename, t_cube *cube)
{
	(void) filename;
	if (!cube->floor.init || !cube->ceiling.init)
		return (false);
	return (true);
}

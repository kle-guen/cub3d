/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:17:49 by snourry           #+#    #+#             */
/*   Updated: 2023/01/28 12:46:49 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_flag(const char *flag);
static bool	exist(int flag, char *str, t_cube *cube);

/**
 * @brief Function is used to check texture line.
 */
bool	texture(const char *flag, char *line, t_cube *cube)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		k;

	i = 2;
	if (!(line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))))
		return (false);
	k = get_flag(flag);
	if (cube->texture[k].img)
		return (false);
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i])
		return (false);
	j = ft_strlen(&line[i]);
	if (line[i + j - 1] == '\n')
		j--;
	str = ft_substr(&line[i], 0, j);
	if (!exist(k, str, cube))
		return (false);
	return (true);
}

/**
 * @brief Function is used to get the flag id.
 */
static int	get_flag(const char *flag)
{
	static const char	*src[] = {"NO", "SO", "EA", "WE", "PO"};
	int					i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(flag, src[i]) == 0)
			return (i);
		i++;
	}
	return (0);
}

/**
 * @brief Function is used to check if file exist and apply if it exist.
 */
static bool	exist(int flag, char *str, t_cube *cube)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		cube->texture[flag].img = mlx_xpm_file_to_image(cube->mlx, str, \
		&cube->texture[flag].w, &cube->texture[flag].h);
		cube->texture[flag].buff = mlx_get_data_addr(cube->texture[flag].img, \
		&cube->pixel_bits, &cube->line_bytes, &cube->endian);
		cube->texture[flag].x = 0;
		cube->texture[flag].pos = 0;
		cube->texture[flag].step = 0;
	}
	free(str);
	str = NULL;
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

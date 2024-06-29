/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:19:22 by snourry           #+#    #+#             */
/*   Updated: 2023/02/01 13:15:57 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_color	get_color(char *str);
static t_color	get_color2(t_color colo, char **tab);
static bool		check(char *str);
static size_t	satoi(char *str);

/**
 * @brief Function is used to get color.
 */
bool	color(const char *flag, char *line, t_cube *cube)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 1;
	if (!(line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))))
		return (false);
	if ((flag[0] == 'F' && cube->floor.init) || cube->ceiling.init)
		return (false);
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i])
		return (false);
	j = ft_strlen(&line[i]);
	if (line[i + j - 1] == '\n')
		j--;
	str = ft_substr(&line[i], 0, j);
	if (flag[0] == 'F')
	{
		cube->floor = get_color(str);
		return (cube->floor.init);
	}
	cube->ceiling = get_color(str);
	return (cube->ceiling.init);
}

static t_color	get_color(char *str)
{
	char	**tab;
	t_color	color;

	color.init = false;
	color.red = 0;
	color.green = 0;
	color.blue = 0;
	if (!check(str))
		return (color);
	tab = ft_split(str, ',');
	free(str);
	str = NULL;
	if (!tab)
	{
		error(ERROR_ALLOC);
		return (color);
	}
	color = get_color2(color, tab);
	return (color);
}

static t_color	get_color2(t_color color, char **tab)
{
	int		tmp[3];

	tmp[0] = satoi(tab[0]);
	tmp[1] = satoi(tab[1]);
	tmp[2] = satoi(tab[2]);
	if (tmp[0] == -1 || tmp[1] == -1 || tmp[2] == -1)
	{
		free(tab);
		tab = NULL;
		return (color);
	}
	color.init = true;
	color.red = tmp[0];
	color.green = tmp[1];
	color.blue = tmp[2];
	free(tab);
	tab = NULL;
	return (color);
}

static bool	check(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ','))
			return (false);
		if (str[i] == ',')
		{
			if (i == 0 || !str[i + 1])
				return (false);
			j++;
		}
		i++;
	}
	if (j != 2)
		return (false);
	return (true);
}

static size_t	satoi(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 3)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	free(str);
	str = NULL;
	if (result > 255)
		return (-1);
	return (result);
}

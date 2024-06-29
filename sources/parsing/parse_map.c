/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:17:09 by snourry           #+#    #+#             */
/*   Updated: 2022/12/14 22:54:07 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	line_identifier(char *line, int fd, t_cube *cube);

/**
 * @brief Function is used to define values of cube after checking.
 */
bool	parse_map(const char *filename, t_cube *cube)
{
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	str = get_next_line(fd);
	while (str)
	{
		if (!line_identifier(str, fd, cube))
		{
			free(str);
			str = NULL;
			gnl_clear(fd);
			close(fd);
			return (false);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (true);
}

/**
 * @brief Struct for create a Singleton.
 */
typedef struct s_parse
{
	bool		((*f)(const char *, char *, t_cube *));
	const char	*flag;
}				t_parse;

/**
 * @brief Function is used to parse a line.
 */
static bool	line_identifier(char *line, int fd, t_cube *cube)
{
	static const t_parse	parse[] = {
	{&texture, "NO"}, {&texture, "SO"},
	{&texture, "EA"}, {&texture, "WE"},
	{&color, "F"}, {&color, "C"}};
	int						i;
	int						j;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i] || line[i] == '\n')
		return (true);
	j = 0;
	while (j < 6)
	{
		if (ft_strncmp(&line[i], parse[j].flag, ft_strlen(parse[j].flag)) == 0)
			return (parse[j].f(parse[j].flag, &line[i], cube));
		j++;
	}
	return (map(line, fd, cube));
}

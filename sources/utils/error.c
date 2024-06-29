/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:28:48 by snourry           #+#    #+#             */
/*   Updated: 2023/01/18 06:25:28 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Function is used to write error messages.
 * 
 * @param t_message Allows you to select the error message.
 */
void	error(t_message message)
{
	static const char	*str[] = {
		"Malloc failed.\n",
		"Usage: ./cub3d <map.cub>.\n",
		"The map extension isn't correct.\n",
		"The map don't have a name.\n",
		"The map file doesn't exist.\n",
		"The map texture isn't correct.\n",
		"The map color isn't correct.\n",
		"The map isn't correct.\n",
		"The map need spawn point.\n",
		"The map file contains an error.\n"
	};

	ft_putstr_fd("[\e[31mERROR\e[39m] ", 2);
	ft_putstr_fd((char *)str[message], 2);
}

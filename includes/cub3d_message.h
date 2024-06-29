/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:37:38 by snourry           #+#    #+#             */
/*   Updated: 2022/11/30 13:37:38 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MESSAGE_H
# define CUB3D_MESSAGE_H

typedef enum e_message
{
	ERROR_ALLOC,
	ERROR_USAGE,
	ERROR_EXTENSION,
	ERROR_NAME,
	ERROR_EXIST,
	ERROR_TEXTURE,
	ERROR_COLOR,
	ERROR_MAP,
	ERROR_SPAWN,
	ERROR_READ
}	t_message;

void	error(t_message message);

#endif

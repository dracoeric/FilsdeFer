/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:18:54 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:46:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		fdf_free_map(t_map **map)
{
	t_map	*bubble;
	t_map	*prev;

	if (map == 0)
		return (-1);
	bubble = *map;
	while (bubble != 0)
	{
		prev = bubble;
		bubble = bubble->next;
		free(prev->coord);
		free(prev);
	}
	*map = 0;
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:47:40 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 12:15:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static	t_map	*fdf_create_map_point(
t_map			*fdf_read_map(int fd);
{
	char	*line;
	t_map	*map;
	char	**split;

	line = 0;
	prev_line = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, 32);
		free(line);
		fdf_add_to_map(*map, split);
	}
}

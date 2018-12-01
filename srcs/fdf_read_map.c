/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:47:40 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:26:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static	t_map		*fdf_create_map_point(char *data, int x, int y)
{
	t_map		*elem;
	t_mapcoord	*coord;
	char		*ptr;
	t_colour	colour;

	if (!(elem = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(coord = (t_mapcoord *)malloc(sizeof(t_mapcoord))))
	{
		free(elem);
		return (0);
	}
	coord->mx = x;
	coord->my = y;
	elem->coord = coord;
	elem->next = 0;
	elem->right = 0;
	elem->bot = 0;
	if ((ptr = ft_strchr(data, ',')))
		*(ptr++) = '\0';
	coord->mz = ft_atoi(data);
	colour = (ptr == 0 ? 0 : mlx_str_to_colour(ptr));
	elem->colour = colour;
	return (elem);
}

static	void		fdf_map_add_front(t_map **map, t_map *elem, int *first)
{
	if (map == 0 || elem == 0)
		return ;
	if (*map == 0)
	{
		*map = elem;
		*first = 0;
	}
	else
	{
		if (*first == 1)
			*first = 0;
		else
			(*map)->right = elem;
		elem->next = *map;
		*map = elem;
	}
}

static	int			fdf_add_to_map(t_fdf_param *param, t_map **map,
						char **split, int y)
{
	static	t_map	*bubble = 0;
	int				x;
	int				first;
	t_map			*elem;
	t_map			*first_of_line;

	x = 0;
	first = 1;
	while (split[x] != 0)
	{
		if (!(elem = fdf_create_map_point(split[x], x, y)))
			return (fdf_free_map(map));
		if (first == 1)
			first_of_line = elem;
		fdf_map_add_front(map, elem, &first);
		if (bubble != 0)
		{
			bubble->bot = elem;
			bubble = bubble->right;
		}
		x++;
	}
	param->map_width = x;
	bubble = first_of_line;
	return (1);
}

t_map				*fdf_read_map(t_fdf_param *param, int fd)
{
	char	*line;
	t_map	*map;
	char	**split;
	int		y;

	line = 0;
	y = 0;
	map = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, 32);
		free(line);
		if (fdf_add_to_map(param, &map, split, y) == -1)
		{
			free(split);
			return (0);
		}
		free(split);
		y++;
	}
	param->map_height = y;
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:47:40 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 15:42:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static	int			fdf_alter_z(char *data)
{
	int z;

	z = ft_atoi(data);
	if (z <= -50 && z >= -20)
		return (-20 + (z + 20) / 4);
	else if (z >= 3 && z <= 25)
		return (3 + (z - 3) / 4);
	else if (z > 25 && z <= 105)
		return (7 + (z - 25) / 20);
	else if (z > 105)
		return (11 + (z - 105) / 50);
	return (z);
}

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
	coord->mz = fdf_alter_z(data);
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
	int		x_max;

	line = 0;
	y = 0;
	map = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x_max = 0;
		split = ft_strsplit(line, 32);
		free(line);
		while (split[x_max] != 0)
			x_max++;
		if (!split || fdf_add_to_map(param, &map, split, y++) == -1)
		{
			ft_free_mat_char(split, x_max);
			return (0);
		}
		ft_free_mat_char(split, x_max);
	}
	param->map_height = y;
	return (map);
}

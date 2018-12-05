/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:07:30 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 15:16:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

int		fdf_free_param(t_fdf_param **param, int map, int img, int cossin)
{
	if (map == 1)
		fdf_free_map(&((*param)->map));
	if (img % 10 == 1)
	{
		mlx_destroy_image((*param)->mlx_ptr, (*param)->img->ptr);
		free((*param)->img);
	}
	if (img / 10 == 1)
	{
		mlx_destroy_image((*param)->mlx_ptr, (*param)->img_top->ptr);
		free((*param)->img_top);
	}
	if (img / 100 == 1)
	{
		mlx_destroy_image((*param)->mlx_ptr, (*param)->img_bot->ptr);
		free((*param)->img_bot);
	}
	if (cossin % 10 == 1)
		free((*param)->cos);
	if (cossin / 10 == 1)
		free((*param)->sin);
	if (cossin / 100 == 1)
		ft_free_mat_int((*param)->rot, 3);
	free(*param);
	return (-1);
}

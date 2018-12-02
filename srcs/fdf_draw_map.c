/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:23:17 by erli              #+#    #+#             */
/*   Updated: 2018/12/02 17:13:01 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

static	t_mapcoord	*fdf_euler_rotation(t_fdf_param *param, t_map *point)
{
	t_mapcoord *coord;
	t_mapcoord *origin;

	if (!(coord = (t_mapcoord *)malloc(sizeof(t_mapcoord))))
		return (0);
	origin = point->coord;
	coord->mx = param->euler[0][0] * (origin->mx - (param->map_width / 2));
	coord->mx += param->euler[0][1] * (origin->my - (param->map_height / 2));
	coord->mx += param->euler[0][2] * origin->mz;
	coord->my = param->euler[1][0] * (origin->mx - (param->map_width / 2));
	coord->my += param->euler[1][1] * (origin->my - (param->map_height / 2));
	coord->my += param->euler[1][2] * origin->mz;
	coord->mz = param->euler[2][0] * (origin->mx - (param->map_width / 2));
	coord->mz += param->euler[2][1] * (origin->my - (param->map_height / 2));
	coord->mz += param->euler[2][2] * origin->mz;
	coord->mx = (coord->mx / 1000 + (param->map_width / 2)) * param->zoom;
	coord->my = (coord->my / 1000 + (param->map_height / 2)) * param->zoom;
	coord->mz = (coord->mz / 1000) * param->zoom;
	return (coord);
}

static	t_pixcoord	*fdf_mcoord_to_pcoord(t_fdf_param *param, t_map *point)
{
	t_mapcoord *tmp;
	t_pixcoord *pix;
 
	if (param == 0 || point == 0)
		return (0);
	if (!(tmp = fdf_euler_rotation(param, point)))
		return (0);
	if (!(pix = param->proj(tmp)))
	{
		free(tmp);
		return (0);
	}
	pix->px += param->trx;
	pix->py += param->try;
	pix->pz += param->trz;
	free(tmp);
	return (pix);
}

void	fdf_draw_map(t_fdf_param *param)
{
	t_map 		*bubble;
	t_pixcoord	*a;
	t_pixcoord	*b;

	if (param == 0)
		return ;
	bubble = param->map;
	while (bubble != 0)
	{
		a = fdf_mcoord_to_pcoord(param, bubble);
		b = fdf_mcoord_to_pcoord(param, bubble->right);
		mlx_line_put_img(param->img, a, b, param->cg);
		free(b);
		b = fdf_mcoord_to_pcoord(param, bubble->bot);
		mlx_line_put_img(param->img, a, b, param->cg);
		free(b);
		free(a);
		bubble = bubble->next;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img->ptr, 0, LETTERBOX_HEIGHT);
}

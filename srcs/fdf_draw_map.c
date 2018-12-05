/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:23:17 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 13:57:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static	t_mapcoord	*fdf_rotation(t_fdf_param *param, t_map *point)
{
	t_mapcoord	*coord;
	int			x;
	int			y;
	int			z;

	if (!(coord = (t_mapcoord *)malloc(sizeof(t_mapcoord))))
		return (0);
	x = point->coord->mx * param->zoom - param->map_width * param->zoom / 2;
	y = point->coord->my * param->zoom - param->map_height * param->zoom / 2;
	z = point->coord->mz * param->coef_alt;
	if (z > param->max_z)
		param->max_z = z;
	if (z < param->min_z)
		param->min_z = z;
	coord->mx = param->rot[0][0] * x + param->rot[0][1] * y;
	coord->mx += param->rot[0][2] * z;
	coord->my = param->rot[1][0] * x + param->rot[1][1] * y;
	coord->my += param->rot[1][2] * z;
	coord->mz = param->rot[2][0] * x + param->rot[2][1] * y;
	coord->mz += param->rot[2][2] * z;
	coord->mx = coord->mx / 1000 + param->map_width * param->zoom / 2;
	coord->my = coord->my / 1000 + param->map_height * param->zoom / 2;
	coord->mz = coord->mz / 1000;
	return (coord);
}

static	t_pixcoord	*fdf_mcoord_to_pcoord(t_fdf_param *param, t_map *point)
{
	t_mapcoord	*tmp;
	t_pixcoord	*pix;

	if (param == 0 || point == 0)
		return (0);
	if (!(tmp = fdf_rotation(param, point)))
		return (0);
	if (!(pix = param->proj(tmp)))
	{
		free(tmp);
		return (0);
	}
	pix->px += param->trx;
	pix->py += param->try;
	pix->pz = point->coord->mz * param->coef_alt;
	free(tmp);
	return (pix);
}

void				fdf_draw_map(t_fdf_param *param)
{
	t_map		*bubble;
	t_pixcoord	*a;
	t_pixcoord	*b;

	if (param == 0)
		return ;
	param->max_z = 0;
	param->min_z = 0;
	bubble = param->map;
	while (bubble != 0)
	{
		a = fdf_mcoord_to_pcoord(param, bubble);
		b = fdf_mcoord_to_pcoord(param, bubble->right);
		fdf_line_put_img(param, a, b, param->cg);
		free(b);
		b = fdf_mcoord_to_pcoord(param, bubble->bot);
		fdf_line_put_img(param, a, b, param->cg);
		free(b);
		free(a);
		bubble = bubble->next;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img->ptr, 0, LETTERBOX_HEIGHT);
	fdf_debug_print_param(param);
}

/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:36:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 11:55:29 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

static	int		fdf_init_rot(t_fdf_param *param)
{
	int	**mat;

	if (!(mat = fdf_make_rot_mat(param)))
		return (fdf_free_param(&param, 1, 111, 11));
	param->rot = mat;
	return (1);
}

static	int		fdf_init_img(t_fdf_param *param)
{
	t_img	*img;

	if (!(img = mlx_img_create(param->mlx_ptr, PIX_WIDTH, LETTERBOX_HEIGHT)))
		return (0);
	param->img_top = img;
	if (!(img = mlx_img_create(param->mlx_ptr, PIX_WIDTH, LETTERBOX_HEIGHT)))
		return (fdf_free_param(&param, 1, 10, 0));
	param->img_bot = img;
	if (!(img = mlx_img_create(param->mlx_ptr, PIX_WIDTH, PIX_HEIGHT)))
		return (fdf_free_param(&param, 1, 110, 0));
	param->img = img;
	return (1);
}

static	void	fdf_init_others(t_fdf_param *param)
{
	int		zoom1;
	int		zoom2;

	param->coef_alt = DEFAULT_COEF_ALT;
	zoom1 = PIX_WIDTH / param->map_width * 8 / 10;
	zoom2 = PIX_HEIGHT / param->map_height * 8 / 10;
	param->zoom = (zoom1 < zoom2 ? zoom1 : zoom2);
	param->max_z = 0;
	param->min_z = 0;
	param->rotx = DEFAULT_ROTX % 360;
	while (param->rotx < 0)
		param->rotx += 360;
	param->roty = DEFAULT_ROTY % 360;
	while (param->roty < 0)
		param->roty += 360;
	param->rotz = DEFAULT_ROTZ % 360;
	while (param->rotz < 0)
		param->rotz += 360;
	param->trx = (PIX_WIDTH - param->zoom * param->map_width) / 2;
	param->try = (PIX_HEIGHT - param->zoom * param->map_height) / 2;
	param->trz = DEFAULT_TRZ;
	param->cg = &mlx_colourgiver_uni;
	param->proj = &mlx_para_proj;
}

static	int		fdf_init_cossin(t_fdf_param *param)
{
	int	*tab;
	int	i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 360)))
		return (fdf_free_param(&param, 1, 111, 0));
	while (i < 360)
	{
		tab[i] = (int)(cos(i * M_PI / 180) * 1000);
		i++;
	}
	param->cos = tab;
	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 360)))
		return (fdf_free_param(&param, 1, 111, 1));
	while (i < 360)
	{
		tab[i] = (int)(sin(i * M_PI / 180) * 1000);
		i++;
	}
	param->sin = tab;
	return (1);
}

t_fdf_param		*fdf_init(int fd)
{
	t_fdf_param		*param;
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			*map;

	if (!(mlx_ptr = mlx_init()))
		return (0);
	if (!(win_ptr = mlx_new_window(mlx_ptr, PIX_WIDTH,
		PIX_HEIGHT + 2 * LETTERBOX_HEIGHT, "FdF")))
		return (0);
	if (!(param = (t_fdf_param *)malloc(sizeof(t_fdf_param))))
		return (0);
	if (!(map = fdf_read_map(param, fd)))
		return ((fdf_free_param(&param, 0, 0, 0) == -1 ? NULL : NULL));
	param->map = map;
	param->mlx_ptr = mlx_ptr;
	param->win_ptr = win_ptr;
	if (fdf_init_img(param) == -1)
		return (0);
	if (fdf_init_cossin(param) == -1)
		return (0);
	fdf_init_others(param);
	if (fdf_init_rot(param) == -1)
		return (0);
	return (param);
}

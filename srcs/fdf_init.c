/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:36:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 17:47:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

static	int		fdf_init_img(t_fdf_param *param)
{
	t_img	*img;

	if (!(img = mlx_img_create(param->mlx_ptr, PIX_WIDTH, 150)))
		return (0);
	param->img_top = img;
	if (!(img = mlx_img_create(param->mlx_ptr, PIX_WIDTH, 150)))
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

	param->coef_alt = COEF_ALT_DEFAULT;
	zoom1 = PIX_WIDTH / param->map_width * 8 / 10;
	zoom2 = PIX_HEIGHT / param->map_height * 8 / 10;
	param->zoom = (zoom1 < zoom2 ? zoom1 : zoom2);
	param->rotx = 0;
	param->roty = 0;
	param->rotz = 0;
	param->trx = 0;
	param->try = 0;
	param->trz = 0;
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
		PIX_HEIGHT + 300, "FdF")))
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
	return (param);
}

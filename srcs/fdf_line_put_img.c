/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:33:10 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 14:25:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	draw_line_case1(t_fdf_param *param, t_pixcoord *a,
					t_pixcoord *b, t_colour (*f)(t_fdf_param *, int))
{
	int x;
	int x_diff;
	int y;
	int z;
	int x_pro;

	x = a->px;
	x_diff = b->px - a->px;
	while (x <= b->px)
	{
		x_pro = x - a->px;
		if (x_diff != 0)
		{
			z = a->pz + x_pro * (b->pz - a->pz) / x_diff;
			y = a->py + x_pro * (b->py - a->py) / x_diff;
		}
		else
		{
			z = a->pz;
			y = a->py;
		}
		mlx_pixel_put_img(param->img, x, y, f(param, z));
		x++;
	}
}

static	void	draw_line_case2(t_fdf_param *param, t_pixcoord *a,
					t_pixcoord *b, t_colour (*f)(t_fdf_param *, int))
{
	int x;
	int y_diff;
	int y;
	int z;
	int	y_pro;

	y = a->py;
	y_diff = b->py - a->py;
	while (y <= b->py)
	{
		y_pro = y - a->py;
		z = a->pz + y_pro * (b->pz - a->pz) / y_diff;
		x = a->px + y_pro * (b->px - a->px) / y_diff;
		mlx_pixel_put_img(param->img, x, y, f(param, z));
		y++;
	}
}

void			fdf_line_put_img(t_fdf_param *param, t_pixcoord *a,
					t_pixcoord *b, t_colour (*f)(t_fdf_param *, int))
{
	int	y_diff;
	int x_diff;

	if (a == 0 || b == 0)
		return ;
	y_diff = b->py - a->py;
	x_diff = b->px - a->px;
	if (x_diff >= 0 && x_diff >= (y_diff < 0 ? -y_diff : y_diff))
		draw_line_case1(param, a, b, f);
	else if (x_diff < 0 && -x_diff >= (y_diff < 0 ? -y_diff : y_diff))
		draw_line_case1(param, b, a, f);
	else if (y_diff > 0 && y_diff >= (x_diff < 0 ? -x_diff : x_diff))
		draw_line_case2(param, a, b, f);
	else
		draw_line_case2(param, b, a, f);
}

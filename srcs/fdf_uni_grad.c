/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_uni_grad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:10:05 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 10:25:30 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colour	fdf_uni_grad(t_fdf_param *param, int z)
{
	int			delta_z;
	int			delta_r;
	int			delta_g;
	int			delta_b;
	t_colour	colour;

	colour = param->colour_bot;
	delta_z = param->max_z - param->min_z;
	if (delta_z == 0)
		return (colour);
	delta_b = (param->colour_top % 256) - (colour % 256);
	delta_g = (param->colour_top / 256) % 256 - (colour / 256) % 256;
	delta_r = (param->colour_top / 65536) % 256 - (colour / 65536) % 256;
	colour += (int)(delta_b * ((double)(z - param->min_z)
		/ (double)delta_z));
	colour += 256 * (int)(delta_g * ((double)(z - param->min_z)
		/ (double)delta_z));
	colour += 65536 * (int)(delta_r * ((double)(z - param->min_z)
		/ (double)delta_z));
	return (colour);
}

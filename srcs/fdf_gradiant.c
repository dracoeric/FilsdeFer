/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:07:20 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 13:48:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colour	fdf_gradiant(t_fdf_param *param, int z)
{
	int z_real;

	z_real = z / param->coef_alt;
	if (param == 0)
		return (0);
	if (z_real < -50)
		return (mlx_str_to_colour("0x00000843"));
	else if (z_real < -20)
		return (mlx_str_to_colour("0x00150e88"));
	else if (z_real < -10)
		return (mlx_str_to_colour("0x00033c99"));
	else if (z_real < 1)
		return (mlx_str_to_colour("0x00000fe3"));
	else if (z_real < 3)
		return (mlx_str_to_colour("0x00fbeeba"));
	else if (z_real < 7)
		return (mlx_str_to_colour("0x0038a445"));
	else if (z_real < 11)
		return (mlx_str_to_colour("0x00884f05"));
	else
		return (mlx_str_to_colour("0x00f8fefe"));
}

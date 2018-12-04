/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:07:20 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 14:33:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colour	fdf_gradiant(t_fdf_param *param, int z)
{
	if (param == 0)
		return (0);
	if (z < -100)
		return (mlx_str_to_colour("0x00000843"));
	else if (z < -50)
		return (mlx_str_to_colour("0x00150e88"));
	else if (z < -20)
		return (mlx_str_to_colour("0x00033c99"));
	else if (z < 0)
		return (mlx_str_to_colour("0x00000fe3"));
	else if (z < 20)
		return (mlx_str_to_colour("0x00fbeeba"));
	else if (z < 50)
		return (mlx_str_to_colour("0x0038a445"));
	else if (z < 300)
		return (mlx_str_to_colour("0x00884f05"));
	else
		return (mlx_str_to_colour("0x00f8fefe"));
}

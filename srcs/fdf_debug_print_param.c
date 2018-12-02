/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_print_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:24:48 by erli              #+#    #+#             */
/*   Updated: 2018/12/02 16:08:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	fdf_debug_print_param(t_fdf_param *param)
{
	fdf_debug_print_map(param->map);
	ft_printf("map width = %d\nmap height = %d\ncoef_alt = %d\nzoom = %d\n",
		param->map_width, param->map_height, param->coef_alt, param->zoom);
	ft_printf("phi = %d\ntheta = %d\npsi = %d\ntrx = %d\ntry = %d\n",
		param->phi, param->theta, param->psi, param->trx, param->try);
	ft_printf("trz = %d\ncos =%t4d\nsin =%t4d\n",
		param->trz, param->cos, 12, param->sin, 12);
	ft_printf("fin print_param\n\n\n");
}

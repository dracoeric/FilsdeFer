/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:27:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:48:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, t_colour colour)
{
	int		i;
	int		*int_ptr;

	if (img == 0)
		return ;
	i = x * (img->bypp) + y * img->size_line;
	int_ptr = (int *)((img->str) + i);
	int_ptr[0] = colour;
}

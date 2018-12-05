/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:27:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/05 10:45:48 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "libft.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, t_colour colour)
{
	int			i;
	t_colour	*int_ptr;

	if (img == 0)
		return ;
	if (x < 0 || y < 0 || x > img->size_line / img->bypp || y > img->nb_line)
		return ;
	i = x * (img->bypp) + y * img->size_line;
	if (i > img->size_line * y  && i < (img->size_line * (y + 1)))
	{
		int_ptr = (t_colour *)((img->str) + i);
		int_ptr[0] = colour;
	}
}

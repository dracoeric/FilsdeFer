/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:14:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:51:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	fdf_init_display(t_fdf_param *param)
{
	t_colour	colour;
	int			i;
	t_colour	*tabtop;
	t_colour	*tabbot;
	int			len;

	colour =  mlx_str_to_colour(LETTERBOX_COLOUR);
	i = 0;
	tabtop = (t_colour *)param->img_top->str;
	tabbot = (t_colour *)param->img_bot->str;
	len = param->img_top->size_line * param->img_top->nb_line
		/ param->img_top->bypp;
	while (i < len)
	{
		tabtop[i] = colour;
		tabbot[i] = colour;
		i++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_top->ptr, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_bot->ptr, 0, PIX_HEIGHT + LETTERBOX_HEIGHT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:07:30 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:47:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		fdf_free_param(t_fdf_param **param, int map, int img, int cossin)
{
	if (map == 1)
		fdf_free_map(&((*param)->map));
	if (img % 10 == 1)
	{
		free((*param)->img->str);
		free((*param)->img);
	}
	if (img / 10 == 1)
	{
		free((*param)->img_top->str);
		free((*param)->img_top);
	}
	if (img / 100 == 1)
	{
		free((*param)->img_bot->str);
		free((*param)->img_bot);
	}
	if (cossin % 10 == 1)
		free((*param)->cos);
	if (cossin / 10 == 1)
		free((*param)->sin);
	free(*param);
	return (-1);
}

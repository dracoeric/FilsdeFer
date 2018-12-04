/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:27 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 16:35:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

void	fdf_redraw(t_fdf_param *para)
{
	free(para->rot);
	if (!(para->rot = fdf_make_rot_mat(para)))
	{
		fdf_free_param(&para, 1, 111, 11);
		exit(0);
	}
	ft_bzero(para->img->str, para->img->size_line * para->img->nb_line + 1);
	fdf_draw_map(para);
}

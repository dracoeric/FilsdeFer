/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_para_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:34:16 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 13:57:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include <stdlib.h>

t_pixcoord	*mlx_para_proj(t_mapcoord *a)
{
	t_pixcoord *pix;

	if (a == NULL || !(pix = (t_pixcoord *)malloc(sizeof(t_mapcoord))))
		return (NULL);
	pix->px = a->mx + PARA_COEFF * a->mz / 1000;
	pix->py = a->my + PARA_COEFF * a->mz / 2000;
	pix->pz = a->mz;
	return (pix);
}

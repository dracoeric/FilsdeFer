/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_para_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:34:16 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 11:38:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include <stdlib.h>

t_pixcoord	*mlx_para_proj(t_mapcoord *a)
{
	t_pixcoord *pix;

	if (a == NULL || !(pix = (t_pixcoord *)malloc(sizeof(t_mapcoord))))
		return (NULL);
	pix->px = a->px + PARA_COEFF * a->pz / 1000;
	pix->py = a->py + PARA_COEFF * a->pz / 2000;
	pix->pz = a->pz;
	return (pix);
}

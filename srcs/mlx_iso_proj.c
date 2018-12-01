/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_iso_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:34:16 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 11:40:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include <stdlib.h>

t_pixcoord	*mlx_iso_proj(t_mapcoord *a)
{
	t_pixcoord *pix;

	if (a == NULL || !(pix = (t_pixcoord *)malloc(sizeof(t_mapcoord))))
		return (NULL);
	pix->px = (ISO_COEFF1 * a->px  ISO_COEFF2 * a->py) / 1000;
	pix->py = a->pz + (ISO_COEFF1 * a->px + ISO_COEFF2 * a->py) / 2000;
	pix->pz = a->pz;
	return (pix);
}

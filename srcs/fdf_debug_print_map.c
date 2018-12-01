/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_print_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:42:13 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 15:01:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	fdf_debug_print_map(t_map *map)
{
	t_map *bubble;

	if (map == 0)
 		ft_printf("void map\n");
	else
	{
		ft_printf("ici\n");
		bubble = map;
		while (bubble != 0)
		{
			ft_printf("bubble '%p', right = '%p', (%d, %d, %d), color = %#.8x\n",
					  bubble, bubble->right, bubble->coord->mx,
					  bubble->coord->my, bubble->coord->mz, bubble->colour);
			bubble = bubble->next;
		}
	}
}

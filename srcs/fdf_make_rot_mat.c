/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_euler_mat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:41:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 12:35:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

static	void	fill_lines(int **mat, t_fdf_param *param)
{
	mat[0][0] = param->cos[param->roty] * param->cos[param->rotz] / 1000;
	mat[0][0] += param->sin[param->rotx] * param->sin[param->roty]
		* param->sin[param->rotz] / 1000000;
	mat[0][1] = 0 - param->cos[param->roty] * param->sin[param->rotz] / 1000;
	mat[0][1] += param->sin[param->rotx] * param->sin[param->roty]
		* param->cos[param->rotz] / 1000000;
	mat[0][2] = param->cos[param->rotx] * param->sin[param->roty] / 1000;
	mat[1][0] = param->cos[param->rotx] * param->sin[param->rotz] / 1000;
	mat[1][1] = param->cos[param->rotx] * param->cos[param->rotz] / 1000;
	mat[1][2] = 0 - param->sin[param->rotx];
	mat[2][0] = 0 - param->sin[param->roty] * param->cos[param->rotz] / 1000;
	mat[2][0] += param->sin[param->rotx] * param->cos[param->roty]
		* param->sin[param->rotz] / 1000000;
	mat[2][1] = param->sin[param->roty] * param->sin[param->rotz] / 1000;
	mat[2][1] += param->sin[param->rotx] * param->cos[param->roty]
		* param->cos[param->rotz] / 1000000;
	mat[2][2] = param->cos[param->rotx] * param->cos[param->roty] / 1000;
}

int				**fdf_make_rot_mat(t_fdf_param *param)
{
	int		**mat;
	int		i;

	if (!(mat = (int **)malloc(sizeof(int *) * 3)))
		return (0);
	i = 0;
	while (i < 3)
	{
		if (!(mat[i] = (int *)malloc(sizeof(int) * 3)))
		{
			ft_free_mat_int(mat, i - 1);
			return (0);
		}
		i++;
	}
	fill_lines(mat, param);
	return (mat);
}

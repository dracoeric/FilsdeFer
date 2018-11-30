/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxadd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:56:03 by erli              #+#    #+#             */
/*   Updated: 2018/11/30 17:54:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXADD_H
# define MLXADD_H

#include "mlx.h"

typedef	int			t_colour;

typedef struct		s_pixcoord
{
	int	px;
	int	py;
	int	pz;
}					t_pixcoord;

typedef	struct		s_mapcoord
{
	int mx;
	int my;
	int mz;
}					t_mapcoord;

typedef	struct		s_img
{
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}					t_img;

typedef	struct		s_mlxwin_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_mlxwin_ptr;

typedef	t_colour	(*t_colourgiver)(int);
typedef	t_pixcoord	(*t_projector)(t_mapcoord);

void				mlx_line_put(t_mlxwin_ptr *mlxwin, t_pixcoord *q,
						t_pixcoord *b, t_colour (*f)(int));
t_colour			mlx_colourgiver_uni(int z);
#endif

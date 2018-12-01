/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:06:03 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 12:01:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "mlxadd.h"

typedef	struct		s_map
{
	t_mapcoord		coord;
	t_colour		colour;
	struct s_map	*next;
	struct s_map	*right;
	struct s_map	*bot;
}					t_map;

typedef	struct		s_fdf_param
{
	t_map			*map;
	int				map_width;
	int				map_height;
	int				coef_alt;
	int				zoom;
	int				rotx;
	int				roty;
	int				rotz;
	int				trx;
	int				try;
	int				trz;
	t_colourgiver	*cg;
	(t_pixcoord *)	(*proj)(t_mapcoord *);
	t_img			*img;
	t_mlxwin_ptr	*mlxwin;
	t_pixcoord		*pcoord;
}					t_fdf_param;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:06:03 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 17:36:27 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "mlxadd.h"

# define PIX_WIDTH 1080
# define PIX_HEIGHT 720
# define COEF_ALT_DEFAULT 10;

typedef	struct		s_map
{
	t_mapcoord		*coord;
	t_colour		colour;
	struct s_map	*next;
	struct s_map	*right;
	struct s_map	*bot;
}					t_map;

typedef	struct		s_fdf_param
{
	void			*mlx_ptr;
	void			*win_ptr;
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
	int				*cos;
	int				*sin;
	t_colour		(*cg)(int);
	t_pixcoord		*(*proj)(t_mapcoord *);
	t_img			*img;
	t_img			*img_top;
	t_img			*img_bot;
}					t_fdf_param;

int					fdf_free_map(t_map **map);
int					fdf_free_param(t_fdf_param **param, int map, int img,
						int cossin);
t_fdf_param			*fdf_init(int fd);
t_map				*fdf_read_map(t_fdf_param *param, int fd);
void				fdf_debug_print_map(t_map *map);
void				fdf_debug_print_param(t_fdf_param *param);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:06:03 by erli              #+#    #+#             */
/*   Updated: 2018/12/02 17:21:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "mlxadd.h"

# define PIX_WIDTH 1080
# define PIX_HEIGHT 720
# define DEFAULT_COEF_ALT 1
# define LETTERBOX_HEIGHT 100
# define LETTERBOX_COLOUR "0x00a0a020"
# define TEXT_COLOUR "0x00ff1d8e"
# define KEY_ESC 53
# define DEFAULT_PSI 0
# define DEFAULT_THETA 30
# define DEFAULT_PHI 00
# define DEFAULT_TRZ -100

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
	int				phi;
	int				theta;
	int				psi;
	int				trx;
	int				try;
	int				trz;
	int				*cos;
	int				*sin;
	int				**euler;
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
int					**fdf_make_euler_mat(t_fdf_param *param);
void				fdf_init_display(t_fdf_param *param, char *filename);
t_map				*fdf_read_map(t_fdf_param *param, int fd);
void				fdf_debug_print_map(t_map *map);
void				fdf_debug_print_param(t_fdf_param *param);
void				fdf_draw_map(t_fdf_param *param);

#endif

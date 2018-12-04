/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:06:03 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 16:29:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "mlxadd.h"

# define PIX_WIDTH 1080
# define PIX_HEIGHT 720
# define DEFAULT_COEF_ALT 5
# define LETTERBOX_HEIGHT 100
# define LETTERBOX_COLOUR "0x00a0a020"
# define TEXT_COLOUR "0x00ff1d8e"
# define KEY_ESC 53
# define DEFAULT_ROTX 60
# define DEFAULT_ROTY 10
# define DEFAULT_ROTZ 40
# define DEFAULT_TRZ -100
# define DEFAULT_TOP_COLOUR "0x00ff0000"
# define DEFAULT_BOT_COLOUR "0x000000ff"

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
	int				max_z;
	int				min_z;
	int				rotx;
	int				roty;
	int				rotz;
	int				trx;
	int				try;
	int				trz;
	int				*cos;
	int				*sin;
	int				**rot;
	t_colour		colour_bot;
	t_colour		colour_top;
	t_colour		(*cg)(struct s_fdf_param *, int);
	t_pixcoord		*(*proj)(t_mapcoord *);
	t_img			*img;
	t_img			*img_top;
	t_img			*img_bot;
}					t_fdf_param;

int					fdf_free_map(t_map **map);
int					fdf_free_param(t_fdf_param **param, int map, int img,
						int cossin);
t_fdf_param			*fdf_init(int fd);
int					**fdf_make_rot_mat(t_fdf_param *param);
void				fdf_init_display(t_fdf_param *param, char *filename);
t_map				*fdf_read_map(t_fdf_param *param, int fd);
void				fdf_debug_print_map(t_map *map);
void				fdf_debug_print_param(t_fdf_param *param);
void				fdf_draw_map(t_fdf_param *param);
void				fdf_redraw(t_fdf_param *param);
t_colour			fdf_gradiant(t_fdf_param *param, int z);
t_colour			fdf_uni_grad(t_fdf_param *param, int z);
void				fdf_line_put_img(t_fdf_param *param, t_pixcoord *a,
						t_pixcoord *b, t_colour (*f)(t_fdf_param *, int));

#endif

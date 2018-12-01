/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:05:44 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 10:16:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "mlxadd.h"
#include "stdlib.h"

#include <stdio.h>

int	deal_key(int key, void *param)
{
	if (param == NULL)
		ft_printf("\n");
	if (key == 53)
		exit(0);
	return (0);
}

int	deal_mouse(int button, int x, int y, void* param)
{
	t_pixcoord *a;
	t_pixcoord *b;
	t_fdf_param *params;

	params = (t_fdf_param *)param;
	a = params->pcoord;
	b = a + 1;
	if (param == NULL)
		return (0);
	if (button == 1)
	{
		a->px = x;
		a->py = y;
		a->pz = 0;
		ft_printf("click with button %d, at (%d, %d)\n", button, x, y);
	}
	if (button == 2)
	{
		b->px = x;
		b->py = y;
		b->pz = 0;
		ft_printf("click with button %d, at (%d, %d)\n", button, x, y);
		mlx_line_put_img(params->img, a, b, &mlx_colourgiver_uni);
		mlx_put_image_to_window(params->mlxwin->mlx_ptr, params->mlxwin->win_ptr,
			params->img->ptr, 0, 0);
	}
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_pixcoord *coord;
	t_mlxwin_ptr *mlxwin;
	t_fdf_param *param;
	t_img	*img;

	ft_printf("Ouverture d'une fenetre\n");
	mlx_ptr = mlx_init();
	if (!(param = (t_fdf_param *)malloc(sizeof(t_fdf_param))))
		return (0);
	if (!(mlxwin = (t_mlxwin_ptr *)malloc(sizeof(t_mlxwin_ptr))))
		return (0);
	if (!(coord = (t_pixcoord *)malloc(sizeof(t_pixcoord) * 2)))
		return (0);
	(coord[0]).px = 0;
	(coord[0]).py = 0;
	(coord[0]).pz = 0;
	param->pcoord = coord;
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "window");
	mlxwin->mlx_ptr = mlx_ptr;
	mlxwin->win_ptr = win_ptr;
	param->mlxwin = mlxwin;
	img = mlx_img_create(mlx_ptr, 500, 500);
	param->img = img;
	mlx_key_hook(win_ptr, &deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, &deal_mouse, param);
	mlx_loop(mlx_ptr);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:05:44 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 17:03:16 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "mlxadd.h"
#include "stdlib.h"
#include <fcntl.h>

int	deal_key_2(int key, t_fdf_param *para)
{
	
	if (key == 0)
		para->trx -= 10;
	if (key == 2)
		para->trx += 10;
	if (key == 15)
		para->zoom += 5;
	if (key == 3)
		para->zoom = (para->zoom <= 5 ? 5 : para->zoom - 5);
	if (key == 17)
		para->coef_alt += 5;
	if (key == 5)
		para->coef_alt = (para->coef_alt <= 5 ? 5 : para->coef_alt - 5);
	if (key == 8)
		para->proj = &mlx_iso_proj;
	if (key == 9)
		para->proj = &mlx_para_proj;
	if (key == 53)
	{
		fdf_free_param(&para, 1, 111, 111);
		exit(0);
	}
	if (key == 2 || key == 0 || key == 15 || key == 3 || key == 17 
		|| key == 5 || key == 8 || key == 9)
		fdf_redraw(para);
	return (0);
}

int	deal_key(int key, void *param)
{
	t_fdf_param *para;

	para = (t_fdf_param *)param;
	if (key == 38)
		para->rotz = (para->rotz < 10 ? para->rotz + 350 : para->rotz - 10);
	if (key == 37)
		para->rotz = (para->rotz >= 350 ? para->rotz - 350 : para->rotz + 10);
	if (key == 34)
		para->rotx = (para->rotx < 10 ? para->rotx + 350 : para->rotx - 10);
	if (key == 40)
		para->rotx = (para->rotx >= 350 ? para->rotx - 350 : para->rotx + 10);
	if (key == 32)
		para->roty = (para->roty < 10 ? para->roty + 350 : para->roty - 10);
	if (key == 31)
		para->roty = (para->roty >= 350 ? para->roty - 350 : para->roty + 10);
	if (key == 13)
		para->try -= 10;
	if (key == 1)
		para->try += 10;
	if (key == 38 || key == 37 || key == 34 || key == 40 
		|| key == 32 || key == 31 || key == 13 || key == 1)
		fdf_redraw(para);
	else
		return (deal_key_2(key, para));
	return (0);
}

int	deal_mouse(int button, int x, int y, void* param)
{
	t_fdf_param *params;

	params = (t_fdf_param *)param;
	if (param == NULL)
		return (0);
	if (button == 1)
	{
		ft_printf("click with button %d, at (%d, %d)\n", button, x, y);
	}
	if (button == 2)
	{
		ft_printf("click with button %d, at (%d, %d)\n", button, x, y);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf_param	*param;
	int			fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_printf("Ouverture d'une fenetre\n");
	if (!(param = fdf_init(fd)))
		return (0);
	fdf_init_display(param, argv[1]);
	fdf_draw_map(param);
	mlx_key_hook(param->win_ptr, &deal_key, param);
	mlx_mouse_hook(param->win_ptr, &deal_mouse, param);
	mlx_loop(param->mlx_ptr);

	return (0);
}

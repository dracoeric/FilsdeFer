/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:05:44 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 19:10:54 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "mlxadd.h"
#include "stdlib.h"
#include <fcntl.h>

int	deal_key(int key, void *param)
{
	t_fdf_param *params;

	params = (t_fdf_param *)param;
	if (param == NULL)
		ft_printf("\n");
	if (key == 53)
	{
		ft_printf("Appuie sur ESC, fermeture\n");
		fdf_free_param(&params, 1, 111, 11);
		exit(0);
	}
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
	t_fdf_param *param;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ft_printf("Ouverture d'une fenetre\n");
	if (!(param = fdf_init(fd)))
		return (0);
	fdf_init_display(param, argv[1]);
	mlx_key_hook(param->win_ptr, &deal_key, param);
	mlx_mouse_hook(param->win_ptr, &deal_mouse, param);
	mlx_loop(param->mlx_ptr);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:05:44 by erli              #+#    #+#             */
/*   Updated: 2018/11/30 11:12:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	ft_printf("Ouverture d'une fenetre\n");
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "First Window");
	mlx_loop(mlx_ptr);

	return (0);
}

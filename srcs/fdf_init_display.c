/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:14:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/04 12:57:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static	void	put_instructions(t_fdf_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 30,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 15, mlx_str_to_colour(TEXT_COLOUR),
		"[w] and [s] for vertical z translation");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 30,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 35, mlx_str_to_colour(TEXT_COLOUR),
		"[a] and [d] for horizontal x translation");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 30,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 55, mlx_str_to_colour(TEXT_COLOUR),
		"[q] and [e] for horizontal y translation");
	mlx_string_put(param->mlx_ptr, param->win_ptr, PIX_WIDTH - 420,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 15, mlx_str_to_colour(TEXT_COLOUR),
		"[i] and [k] for vertical z rotation");
	mlx_string_put(param->mlx_ptr, param->win_ptr, PIX_WIDTH - 420,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 35, mlx_str_to_colour(TEXT_COLOUR),
		"[j] and [l] for horizontal x rotation");
	mlx_string_put(param->mlx_ptr, param->win_ptr, PIX_WIDTH - 420,
		PIX_HEIGHT + LETTERBOX_HEIGHT + 55, mlx_str_to_colour(TEXT_COLOUR),
		"[u] and [o] for horizontal y rotation");
}

static	void	put_to_win(t_fdf_param *param, char *filename)
{
	int	title_offset;

	title_offset = ft_strlen(filename) * 4;
	mlx_string_put(param->mlx_ptr, param->win_ptr, PIX_WIDTH / 2 - 70,
		PIX_HEIGHT / 2 + LETTERBOX_HEIGHT - 20, mlx_str_to_colour(TEXT_COLOUR),
		"Drawing map...");
	mlx_string_put(param->mlx_ptr, param->win_ptr, PIX_WIDTH / 2 - title_offset,
		LETTERBOX_HEIGHT / 2 - 11, mlx_str_to_colour(TEXT_COLOUR),
		filename);
	put_instructions(param);
}

void			fdf_init_display(t_fdf_param *param, char *filename)
{
	t_colour	colour;
	int			i;
	t_colour	*tabtop;
	t_colour	*tabbot;
	int			len;

	colour = mlx_str_to_colour(LETTERBOX_COLOUR);
	i = 0;
	tabtop = (t_colour *)param->img_top->str;
	tabbot = (t_colour *)param->img_bot->str;
	len = param->img_top->size_line * param->img_top->nb_line
		/ param->img_top->bypp;
	while (i < len)
	{
		tabtop[i] = colour;
		tabbot[i] = colour;
		i++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_top->ptr, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_bot->ptr, 0, PIX_HEIGHT + LETTERBOX_HEIGHT);
	put_to_win(param, filename);
}

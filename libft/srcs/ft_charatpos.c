/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charatpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:12:18 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 10:52:30 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_charatpos(unsigned int i, char *str)
{
	write(1, "char '", 6);
	write(1, str, 1);
	write(1, "' at position ", 14);
	ft_putnbr((int)(i));
	write(1, "\n", 1);
}

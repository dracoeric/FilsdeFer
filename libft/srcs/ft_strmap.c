/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:55:37 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 16:09:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *src, char (*f)(char))
{
	size_t	n;
	char	*str;
	size_t	i;

	if (src == NULL)
		return (NULL);
	n = ft_strlen(src);
	str = ft_strnew(n);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = f(src[i]);
		i++;
	}
	str[n] = '\0';
	return (str);
}

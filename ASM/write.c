/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/22 19:38:34 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char	*itoa_base_ulong(uintmax_t n, int base, char *s_base)
{
	uintmax_t			nb;
	unsigned int		i;
	char				*str;
	int					len;
	
	nb = n;
	len = ft_nblen(n, base);
	if (!(str = ft_strnew(len)))
		return (0);
	if (!nb)
		str[0] = '0';
	str[len + 1] = '\0';
	i = 0;
	while (nb)
	{
		str[i] = s_base[nb % base];
		nb /= base;
		i++;
	}
	return (str);
}
 
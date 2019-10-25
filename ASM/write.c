/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/24 21:19:31 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char		*ft_itoa_bse(unsigned int n, int base, int len)
{
	char	*str;
	char	*sbase;

	sbase = "0123456789abcdef";
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = sbase[n % sbase];
		n /= sbase;
		len--;
	}
	return (str);
}

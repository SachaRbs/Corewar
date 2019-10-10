/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:58 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:58 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*ft_strncpy_zero(char *dest, const char *src, size_t n)
{
	char	*from;
	char	*to;

	from = (char*)src;
	to = dest;
	while (n != 0)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	*to = '\0';
	return (dest);
}

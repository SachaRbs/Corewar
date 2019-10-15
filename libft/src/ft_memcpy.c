/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:34 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/15 17:28:20 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			x;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	x = 0;
	// printf("%d", (int)src1[x]);

	while (x < n)
	{
		// printf("%d", (int)src1[x]);
		dst1[x] = src1[x];
		x++;
	}
	// printf("\n");
	return (dst);
}

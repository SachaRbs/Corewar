/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:38 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:38 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*s1;

	i = 0;
	c1 = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == c1)
			return (s1 + i);
		i++;
	}
	return (NULL);
}

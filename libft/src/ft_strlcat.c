/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:05:24 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:30:48 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		n;
	size_t		len_fin;

	n = size;
	dst_cpy = dst;
	src_cpy = src;
	while (n-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	len_fin = dst_cpy - dst;
	n = size - len_fin;
	if (n == 0)
		return (len_fin + ft_strlen((char*)src_cpy));
	while (*src_cpy)
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (len_fin + (src_cpy - src));
}

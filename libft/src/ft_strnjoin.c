/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:58:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/30 17:05:27 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		line1;
	int		line2;
	char	*ret;
	char	*tmp;

	line1 = 0;
	line2 = 0;
	tmp = s1;
	if (!(ret = ft_strnew(ft_strlen(s1) + n + 1)))
		return (NULL);
	while (s1[line1])
	{
		ret[line1] = s1[line1];
		line1++;
	}
	while (s2[line2] && line2 < n)
		ret[line1++] = s2[line2++];
	ret[line1] = 0;
	free(tmp);
	return (ret);
}

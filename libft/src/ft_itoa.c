/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:47 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:47 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(*str) * 2)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0 && n <= 9)
	{
		str[0] = n + 48;
		str[1] = '\0';
	}
	if (n > 9)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(n * -1));
	}
	return (str);
}

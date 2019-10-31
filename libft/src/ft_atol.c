/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:50:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/31 17:50:23 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_atol(const char *str)
{
	int			neg;
	long		ret;

	neg = 1;
	ret = 0;
	while (*str == '\v' || *str == '\t' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0' && *str)
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * neg);
}

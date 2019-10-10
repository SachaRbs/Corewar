/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:53 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:53 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_printf(const char *str)
{
	int		to_return;
	int		sign;
	char	*pointer;

	pointer = (char*)str;
	sign = 1;
	to_return = 0;
	while (((*pointer >= 9 && *pointer <= 13) || *pointer == 32))
		pointer++;
	if (*pointer == '-')
	{
		sign = -1;
		pointer++;
	}
	else if (*pointer == '+')
		pointer++;
	while (*pointer >= '0' && *pointer <= '9')
	{
		to_return = (to_return * 10) + (*pointer - 48);
		pointer++;
	}
	return (to_return * sign);
}

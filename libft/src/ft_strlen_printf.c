/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:53 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:53 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_printf(const char *str)
{
	char	*pointer;

	pointer = (char*)str;
	while (*pointer)
		pointer++;
	return (pointer - str);
}

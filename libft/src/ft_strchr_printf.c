/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:52 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_printf(const char *ptr, int value)
{
	char	*where;

	where = (char*)ptr;
	while (*where != '\0')
	{
		if (*where == (char)value)
			return (where);
		where++;
	}
	if (*where == (char)value)
		return (where);
	return (NULL);
}

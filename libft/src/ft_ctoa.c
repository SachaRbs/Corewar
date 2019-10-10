/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:51 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:51 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(char c)
{
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}

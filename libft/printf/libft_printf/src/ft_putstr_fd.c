/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:56:15 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 13:24:41 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void			ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
		return ((void)NULL);
}
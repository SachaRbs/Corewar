/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:47 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:47 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_fd(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	if (n >= 10)
	{
		ft_print_fd(n / 10, fd);
		ft_print_fd(n % 10, fd);
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
		ft_print_fd(nb, fd);
	}
	else
		ft_print_fd(nb, fd);
}

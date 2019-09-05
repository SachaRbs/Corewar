/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:25:19 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:19:15 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

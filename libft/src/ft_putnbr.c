/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:47:44 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:18:44 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	if (n >= 10)
	{
		ft_print(n / 10);
		ft_print(n % 10);
	}
}

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
		ft_print(nb);
	}
	else
		ft_print(nb);
}

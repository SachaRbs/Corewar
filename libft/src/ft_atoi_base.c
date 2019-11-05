/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:38:57 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/04 17:53:49 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int size, int base)
{
	int			i;
	int			rev;
	long long	nb;

	nb = 0;
	rev = 0;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			rev = 1;
		i++;
	}
	while (i < size)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			nb = nb * base;
			nb = nb + (str[i] - '0');
			i++;
		}
		else if (((str[i] >= 'a') && (str[i] <= 'f')))
		{
			nb = nb * base;
			nb = nb + (str[i] - 'a');
			i++;
		}
	}
	if (rev == 1)
		return (-nb);
	return (nb);
}

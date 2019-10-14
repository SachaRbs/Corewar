/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:58 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/14 11:13:38 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len_str(const char *format, int j)
{
	while (format[j] != '%' && format[j] != '{' && format[j] != '\0')
		j++;
	return (j);
}

int		ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	j;
	va_list			ap;
	char			*result;
	t_specifier		specifier;

	result = ft_dupexit("");
	g_res_len = 0;
	va_start(ap, format);
	j = 0;
	ft_reset_specifier(&specifier, 0);
	while (format[j] != '\0')
	{
		i = j;
		ft_reset_specifier(&specifier, 1);
		result = ft_strnjoin_printf(result, ft_dupexit(format + i),
		g_res_len, (j = count_len_str(format, j)) - i);
		g_res_len += j - i;
		if (format[j] == '%' && get_specif(format + j + 1, &specifier, &j) == 0)
			result = ft_get_argument(&ap, result, &specifier);
		else if (format[j] == '{')
			result = ft_set_color(result, format + j + 1, &j);
	}
	return (ft_final(result, &ap, &specifier));
}

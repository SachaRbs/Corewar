/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:57 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:57 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_fill_flags(const char *format, unsigned int *i,
		t_specifier *specifier)
{
	char			*possible_flags;
	unsigned int	rem_i;

	rem_i = *i;
	possible_flags = ft_dupexit("-+ #0");
	while (ft_strchr(possible_flags, format[*i]) != NULL)
	{
		FLAGS = ft_strnjoin_printf(FLAGS, ft_ctoaexit(format[*i]),
		ft_strlen(FLAGS), 1);
		*i = *i + 1;
	}
	rem_i = 0;
	while (format[rem_i] != CONVERSION)
	{
		if (ft_strchr(possible_flags, format[rem_i]) != NULL
		&& format[rem_i] != '0')
			FLAGS = ft_strnjoin_printf(FLAGS, ft_ctoaexit(format[rem_i]),
			ft_strlen(FLAGS), 1);
		rem_i++;
	}
	free(possible_flags);
}

void			ft_fill_width(const char *format, unsigned int *i,
				t_specifier *specifier)
{
	int				j;
	unsigned int	rem_i;

	rem_i = *i;
	j = (int)*i;
	while (format[*i] >= '0' && format[*i] <= '9' && format[*i])
		*i = *i + 1;
	if (rem_i != *i)
		WIDTH = ft_atoi_printf(format + j);
	else
	{
		rem_i = 0;
		while ((format[rem_i] < '1' || format[rem_i] > '9')
		&& format[rem_i] != CONVERSION && format[rem_i])
			rem_i++;
		if (format[rem_i] != CONVERSION && rem_i != 0 &&
		format[rem_i - 1] != '.')
			WIDTH = ft_atoi_printf(format + rem_i);
	}
}

void			ft_fill_precision(const char *format, unsigned int *i,
				t_specifier *specifier)
{
	int				j;

	if (format[*i] == '.')
	{
		while (format[*i] != CONVERSION)
		{
			if (format[*i] == '.')
				j = (int)*i;
			*i = *i + 1;
		}
		*i = ++j;
		while (format[*i] >= '0' && format[*i] <= '9' && format[*i])
			*i = *i + 1;
		PRECISION = ft_atoi_printf(format + j);
	}
}

void			ft_fill_length(const char *format, unsigned int *i,
				t_specifier *specifier)
{
	int				j;
	unsigned int	rem_i;

	rem_i = *i;
	j = (int)*i;
	while (format[*i] == 'l' || format[*i] == 'h' || format[*i] == 'L'
	|| format[*i] == 'j' || format[*i] == 'z')
		*i = *i + 1;
	LENGTH = ft_strnjoin_printf(LENGTH, ft_dupexit(format + j), 0, (int)*i - j);
	if ((int)*i == j)
	{
		rem_i = 0;
		while (rem_i < *i && format[rem_i] != 'l' && format[rem_i] != 'h' &&
		format[rem_i] != 'L' && format[rem_i] != 'j' && format[rem_i] != 'z')
			rem_i++;
		if (rem_i != *i)
		{
			LENGTH = ft_ctoaexit(format[rem_i]);
			if (format[rem_i + 1] == format[rem_i])
				LENGTH = ft_strnjoin_printf(LENGTH, ft_ctoaexit(format[rem_i]),
				ft_strlen(LENGTH), 1);
		}
	}
	if (ft_strlen(LENGTH) > 1 && LENGTH[0] != LENGTH[1])
		LENGTH[1] = '\0';
}

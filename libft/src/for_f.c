/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:55 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/14 11:23:55 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wi_pr_for_f(char *string, t_specifier *specifier, char wi_fi)
{
	if (ft_strchr(FLAGS, '#') == NULL &&
	PRECISION == 0)
		string[g_str_len - 1] = '\0';
	if (WIDTH > g_str_len)
	{
		if (ft_strchr(FLAGS, '-') == NULL)
			string = ft_strnjoin_printf(ft_nctoaexit(wi_fi, WIDTH -
			g_str_len), string, WIDTH - g_str_len, g_str_len);
		else
			string = ft_strnjoin_printf(string, ft_nctoaexit(wi_fi, WIDTH -
			g_str_len), g_str_len, WIDTH - g_str_len);
		g_str_len = WIDTH;
	}
	return (string);
}

char	*none_f(void *po, t_specifier *specifier)
{
	char				*string;
	char				width_filler;
	long double			*number;

	number = po;
	width_filler = ' ';
	if (ft_strchr(FLAGS, '0') != NULL && PRECISION == -1)
		width_filler = '0';
	if (PRECISION == -1)
		PRECISION = 6;
	if (*number < 0)
	{
		if (!(string = ft_ftoa(-(*number), PRECISION)))
			exit(EXIT_FAILURE);
		string = ft_strnjoin_printf(ft_ctoaexit('-'),
		string, 1, ft_strlen(string));
	}
	else if (!(string = ft_ftoa(*number, PRECISION)))
		exit(EXIT_FAILURE);
	g_str_len = ft_strlen(string);
	string = ft_wi_pr_for_f(string, specifier, width_filler);
	free(po);
	return (string);
}

char	*none_n(void *po, t_specifier *specifier)
{
	char		*string;

	po = NULL;
	specifier = NULL;
	string = ft_ctoaexit(0);
	g_str_len = 0;
	return (string);
}

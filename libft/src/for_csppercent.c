/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_csppercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:54 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/14 11:20:22 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*none_c(void *po, t_specifier *specifier)
{
	char		*string;
	char		wi_fi;
	char		*character;

	wi_fi = ' ';
	character = po;
	string = ft_ctoaexit(*character);
	g_str_len = 1;
	if (ft_strchr(FLAGS, '0') != NULL && ft_strchr(FLAGS, '-') == NULL)
		wi_fi = '0';
	if (WIDTH > g_str_len)
	{
		if (ft_strchr(FLAGS, '-') == NULL)
			string = ft_strnjoin_printf(ft_nctoaexit(wi_fi, WIDTH - g_str_len),
			string, WIDTH - g_str_len, g_str_len);
		else
			string = ft_strnjoin_printf(string, ft_nctoaexit(wi_fi,
			WIDTH - g_str_len), g_str_len, WIDTH - g_str_len);
		g_str_len = WIDTH;
	}
	free(po);
	return (string);
}

char		*ft_wi_pr_for_s(char *string, t_specifier *specifier)
{
	char	wi_fi;

	wi_fi = ' ';
	if (ft_strchr(FLAGS, '0') != NULL && ft_strchr(FLAGS, '-') == NULL)
		wi_fi = '0';
	if (WIDTH > g_str_len)
	{
		if (ft_strchr(FLAGS, '-') == NULL)
			string = ft_strnjoin_printf(ft_nctoaexit(wi_fi, WIDTH - g_str_len),
			string, WIDTH - g_str_len, g_str_len);
		else
			string = ft_strnjoin_printf(string, ft_nctoaexit(wi_fi,
			WIDTH - g_str_len), g_str_len, WIDTH - g_str_len);
		g_str_len = WIDTH;
	}
	return (string);
}

char		*none_s(void *po, t_specifier *specifier)
{
	char		*string;

	if (po == NULL)
		string = ft_dupexit("(null)");
	else
		string = ft_dupexit(po);
	g_str_len = ft_strlen(string);
	if (PRECISION < g_str_len && PRECISION != -1)
	{
		string[PRECISION] = '\0';
		g_str_len = PRECISION;
	}
	return (ft_wi_pr_for_s(string, specifier));
}

char		*none_p(void *po, t_specifier *specifier)
{
	char		*string;

	if ((unsigned long long)(po) == 0 && PRECISION == 0)
		string = ft_dupexit("");
	else if (!(string = ft_itoa_base((unsigned long long)po, 16)))
		exit(EXIT_FAILURE);
	g_str_len = ft_strlen(string);
	if (PRECISION > g_str_len)
		string = ft_strnjoin_printf(ft_nctoaexit('0', PRECISION - g_str_len),
		string, PRECISION - g_str_len, g_str_len);
	g_str_len = ft_strlen(string);
	string = ft_strtolower_printf(ft_strnjoin_printf(ft_dupexit("0x"),
	string, 2, g_str_len));
	g_str_len += 2;
	if (WIDTH > g_str_len)
	{
		if (ft_strchr(FLAGS, '-') == NULL)
			string = ft_strnjoin_printf(ft_nctoaexit(' ', WIDTH - g_str_len),
			string, WIDTH - g_str_len, g_str_len);
		else
			string = ft_strnjoin_printf(string, ft_nctoaexit(' ',
			WIDTH - g_str_len), g_str_len, WIDTH - g_str_len);
		g_str_len = WIDTH;
	}
	return (string);
}

char		*none_percent(void *po, t_specifier *specifier)
{
	char		*string;
	char		wi_fi;
	char		character;

	wi_fi = ' ';
	character = '%';
	string = ft_ctoaexit(character);
	g_str_len = 1;
	if (ft_strchr(FLAGS, '0') != NULL && ft_strchr(FLAGS, '-') == NULL)
		wi_fi = '0';
	if (WIDTH > g_str_len)
	{
		if (ft_strchr(FLAGS, '-') == NULL)
			string = ft_strnjoin_printf(ft_nctoaexit(wi_fi, WIDTH - g_str_len),
			string, WIDTH - g_str_len, g_str_len);
		else
			string = ft_strnjoin_printf(string, ft_nctoaexit(wi_fi,
			WIDTH - g_str_len), g_str_len, WIDTH - g_str_len);
		g_str_len = WIDTH;
	}
	free(po);
	return (string);
}

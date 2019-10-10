/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:48 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:48 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *s)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == ',' || s[len] == '\n' || s[len] == '\t')
		len--;
	len = len - i;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*s_trim;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = ft_len((char *)s);
	if (len < 0)
		len = 0;
	if (!(s_trim = ft_strnew(len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j <= len)
	{
		s_trim[j] = s[i];
		i++;
		j++;
	}
	return (s_trim);
}

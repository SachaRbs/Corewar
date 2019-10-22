/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:10:56 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/17 17:49:22 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char	*itoa_base_ulong(uintmax_t n, int base, char *s_base)
{
	uintmax_t			nb;
	unsigned int		i;
	char				*str;
	int					len;

	nb = n;
	len = ft_nblen(n, base);
	if (!(str = ft_strnew(len)))
		return (0);
	if (!nb)
		str[0] = '0';
	str[len + 1] = '\0';
	i = 0;
	while (nb)
	{
		str[i] = s_base[nb % base];
		nb /= base;
		i++;
	}
	return (str);
}


void	get_champion(t_asm *p, char *str)
{
    char    *end;

	end = NULL;
    if (!ft_strncmp(str, NAME_CMD_STRING, 5) && !p->champ)
    {
        str += 5;
        while (is_whitespace(*str) && *str)
            str++;
        if (*str == '"')
        {
            str++;
            if (!(end = ft_strchr(str, '"')))
                ft_error("INVALID CHAMPION NAME");
        }
        p->champ = ft_strsub(str, 0, end - str);
        if (ft_strlen(p->champ) > PROG_NAME_LENGTH)
            ft_error("CHAMPION NAME TOO LONG");
        printf(GRN"%s\n"RESET, p->champ);
    }
}

void    get_comment(t_asm *p, char *str)
{
    char    *end;

	end = NULL;
    if (!ft_strncmp(str, COMMENT_CMD_STRING, 8) && !p->comment)
    {
        str += 8;
        while (is_whitespace(*str) && *str)
            str++;
        if (*str == '"')
        {
            str++;
            if (!(end = ft_strchr(str, '"')))
                ft_error("INVALID CHAMPION COMMENT");
        }
        p->comment = ft_strsub(str, 0, end - str);
        printf(GRN"%s\n"RESET, p->comment);
        if (ft_strlen(p->comment) > COMMENT_LENGTH)
            ft_error("CHAMPION COMMENT TOO LONG");
    }
}

void    read_header(t_asm *p)
{
  static char     *str;
  char            *buffer;

  str = ft_strnew(1);
  while ((ft_readline(p->fd, &p->str, &buffer) > 0) && !p->f_header)
  {
    get_champion(p, buffer);
    get_comment(p, buffer);
	if (p->champ && p->comment)
		p->f_header = 1;
    p->row++;
  }
  printf("\n");
}

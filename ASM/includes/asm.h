/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:24:03 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/17 17:05:29 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "../libft/includes/libft.h"

#include <stdio.h>

typedef	struct	s_asm
{
	int				fd;
	char			*filename;
	char			*file;
	size_t			linecount;
	char			*champ;
	char			*comment;
	struct s_header	*header;
}				t_asm;


/*
** asm
*/
int		get_champion(t_asm *p, char *str);
int     get_comment(t_asm *p, char *str);

/*
** init
*/

t_asm	*init_struct(int fd);

/*
** utils
*/

int		ft_error(char *str, int err);

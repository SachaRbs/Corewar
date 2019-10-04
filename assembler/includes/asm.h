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

#include "../includes/op.h"
#include "../libft/includes/libft.h"

#include <stdio.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

typedef	struct	s_asm
{
	int				fd;
	char			*filename;
	char			*file;
	size_t			linecount;
	char			*champ;
	char			*comment;
	int				f_label;
	int				f_instr;
	t_op			*op_tab;
	struct s_header	*header;
	struct s_label	*labels;
}				t_asm;

typedef	struct s_label
{
	char			*name;
	struct s_label	*next;
}				t_label;


/*
** asm
*/

void		get_champion(t_asm *p, char *str);
void     	get_comment(t_asm *p, char *str);

/*
** label
*/

void 		print_labels(t_label *head);
t_label 	*add_label(t_asm *p, char **str);

/*
** init
*/

	t_asm *init_struct(int fd);

/*
** utils
*/

int		ft_error(char *str);
int 	is_whitespace(int c);

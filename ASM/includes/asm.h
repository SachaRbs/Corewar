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
	char			*champ;
	char			*comment;
	int				row;
	int				col;
	int				f_header;
	char			*str;
	t_op			*op_tab;
	struct s_token	*tokens;
	struct s_header	*header;
	struct s_label	*labels;
}				t_asm;

typedef struct	s_inst
{
	int 			pos;
	int 			dir_size;
	int 			ocp;
	unsigned int 	wr_size;
	int 			oct;
	unsigned int 	param[3];
}				t_inst;

typedef	struct s_label
{
	char			*name;
	struct s_label	*next;
}				t_label;

int 		ft_readline(int fd, char **str, char **line);

/*
** asm
*/

void 		get_token(t_asm *p, char **line);
void		read_header(t_asm *p);

int 		check_instruction(t_asm *p, char **line, int size);
void		get_instruction(t_asm *p, char **line, int size);

	/*
** label
*/

void 		print_labels(t_label *head);
t_label 	*add_label(t_asm *p, char *str);

/*
** init
*/

t_asm		*init_struct(int fd);

/*
** utils
*/

int		ft_error(char *str);
int 	is_whitespace(int c);
void 	skip_whitespaces(t_asm *p, char **line);

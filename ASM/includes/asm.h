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

#ifndef ASM_H
# define ASM_H

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

#define SPACE " \f\r\t\v"

/*
***		GLOBAL VARIABLES
*/

extern int			g_syntactic_tab[40][12];
extern t_op			g_op_tab[17];

/*
***		ENVIRONMENT STRUCTURE
*/

typedef	struct		s_asm
{
	int				fd;
	char			*filename;
	char			*file;
	char			*champ;
	char			*comment;
	int				f_header;
	char			*str;
	int				byte_pos;
	int				row;
	int				col;
	int				syntax_state;
	t_op			*op_tab;
	struct s_token	*tokens;
	struct s_header	*header;
	struct s_label	*labels;
}					t_asm;

/*
***		DIFFERENT TYPES OF TOKEN
*/

typedef enum		e_type
{
	COMMAND_NAME,
	COMMAND_COMMENT,
	OP,
	LABEL,
	REGISTER,
	INDEX,
	IND_LABEL,
	DIRECT,
	DIRECT_LABEL,
	SEPARATOR,
	NEWLINE
}					t_type;

/*
***		TOKEN INCLUDES BYTE SIZE AND POSITION
*/

typedef struct		s_token
{
	char			*str;
	enum e_type		type;
	int				op_index;
	int				dir_sz;
	int				row;
	int				col;
	int				byte_pos;
	int				byte_sz;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

/*
***		INSTRUCTIONS
*/

typedef struct		s_inst
{
	int 			dir_size;
	int 			ocp;
	unsigned int 	wr_size;
	int 			oct;
	unsigned int 	param[3];
}					t_inst;

/*
***		LABELS
*/

typedef	struct 		s_label
{
	char			*name;
	int				row;
	int				col;
	struct s_label	*next;
}					t_label;

int 				ft_readline(int fd, char **str, char **line);

/*
**		ASM
*/

void 				get_token(t_asm *p, char **line);
void				read_header(t_asm *p);
int 				check_instruction(t_asm *p, char **line, int size);
void				get_instruction(t_asm *p, char **line, int size);

/*
** parser
*/

void				parse(t_asm *p);

/*
** label
*/

void 				print_labels(t_label *head);
t_label 			*add_label(t_asm *p, char *str);

/*
** init
*/

t_asm				*init_struct(int fd);

/*
** error
*/

int					ft_error(char *str);

/*
** utils
*/

int 				is_whitespace(int c);
void 				skip_whitespaces(char **line);
void				skip_comment(char **line);
char				*itoa_base_ulong(uintmax_t n, int base, char *s_base);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:09:05 by epham             #+#    #+#             */
/*   Updated: 2019/11/06 13:23:48 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../includes/op.h"
# include "../../libft/includes/libft.h"

# define RED			"\x1B[31m"
# define RESET			"\x1B[0m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDWHITE		"\033[1m\033[37m"

# define SIZE 2192

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
	char			*line;
	char			*champ;
	char			*comment;
	int				f_header;
	char			*str;
	int				exec_sz;
	int				byte_pos;
	int				row;
	int				col;
	int				syntax_state;
	struct s_token	*tokens;
	struct s_label	*labels;
	struct s_label	*mentions;
}					t_asm;

/*
***		DIFFERENT TYPES OF TOKEN
*/

typedef enum		e_type
{
	NAME,
	COMMENT,
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
***		TYPES AS STRINGS FOR DEBUGGING
*/

static const char *g_typestab[11] =
{
	"NAME",
	"COMMENT",
	"OP",
	"LABEL",
	"REGISTER",
	"INDEX",
	"IND_LABEL",
	"DIRECT",
	"DIRECT_LABEL",
	"SEPARATOR",
	"NEWLINE"
};

/*
***		TOKEN INCLUDES BYTE SIZE AND POSITION
*/

typedef struct		s_token
{
	char			*str;
	enum e_type		type;
	int				op_index;
	int				ocp;
	int				row;
	int				col;
	long			value;
	unsigned int	byte_pos;
	unsigned int	byte_sz;
	unsigned int	exec_sz;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

/*
***		INSTRUCTIONS
*/

typedef struct		s_inst
{
	int				dir_size;
	int				ocp;
	unsigned int	wr_size;
	int				oct;
	unsigned int	param[3];
}					t_inst;

/*
***		LABELS
*/

typedef	struct		s_label
{
	char			*name;
	int				byte_pos;
	int				row;
	int				col;
	struct s_token	*from;
	struct s_label	*next;
}					t_label;

t_asm				*init_struct(int fd, char *filename, char *file);

/*
**		PARSING
*/

int					ft_readline(int fd, char **str, char **line);
void				parse(t_asm *p);
void				parse_symbol(t_asm *p, t_token *new, int start);
void				parse_header(t_asm *p, t_token *newnode);

/*
**		TOKEN MANAGEMENT
*/

t_token				*init_token(t_asm *p, t_type type);
void				add_token(t_asm *p, t_token **head, t_token *newnode);
int					check_token(t_asm *env);
void				print_token(t_token *head);
void				free_tokens(t_token *head);

/*
**		LABEL MANAGEMENT
*/

void				print_labels(t_label *head);
t_label				*add_label(t_asm *p, char *str);
void				print_label_lists(t_asm *env);
void				save_label(t_label **to, t_token *token);
t_label				*check_labels(t_asm *env);

/*
***		UTILS
*/

int					is_instruction(char *line);
int					is_reg(t_asm *p, char *line);
int					is_whitespace(int c);
int					is_divider(int c);
void				skip_whitespaces(t_asm *p, char *line);
void				skip_comment(t_asm *p, char *line);

/*
**		ERROR
*/

int					get_error(t_asm *env, t_token *token);
void				print_error(t_asm *p);
int					ft_error(char *str);
int					lexical_error(t_asm *p, int errcode);

/*
***		ENCODING
*/

int					create_file(char *filename);
char				*write_header(t_asm *p);
void				write_to_file(t_asm *p);
void				write_byte(char *byte, int pos, int value, size_t size);
void				get_exec_sz(t_asm *p);
char				*write_exec(t_asm *p);
void				get_ocp(t_token **token);
int					ocp_2_args(t_token *token);
int					ocp_3_args(t_token *token);

/*
***		FREE
*/

void				free_asm(t_asm *env);

#endif

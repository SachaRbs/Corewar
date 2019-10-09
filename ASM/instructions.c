/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:27:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/25 17:27:06 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int     is_instruction(t_asm *p, char *line)
{
    int     i;

    i = 0;
    while (p->op_tab[i].name)
    {
        if(!ft_strcmp(p->op_tab[i].name, line))
            return (i);
        i++;
    }
    return (0);
}

int		check_instruction(t_asm *p, char **line, int size)
{
    char    *str;

    str = ft_strndup(*line, size);
    if (is_instruction(p, str))
    {
        printf(RED "%s\n" RESET, str);
        return (1);
    }
    else
    {
        printf("INSTRUCTION: %s NOT VALID\n", *line);
        return (0);
    }
}

void    init_instruction(t_asm *p, t_inst **instruction, int flag)
{
    t_inst  *tmp;

	if (!flag)
		*instruction = malloc(sizeof(t_inst));
	else
	{
    	tmp = *instruction;
    	tmp->ocp = 0;
   		tmp->dir_size = p->op_tab[tmp->pos].index;
	}
}

int     handle_instruction(t_asm *p, char **line, t_inst *instruction)
{
    char    **tab;
    int     arg;

	arg = p->op_tab[instruction->pos].nb_arg;
    tab = ft_strsplit(*line, SEPARATOR_CHAR);
}

void    get_instruction(t_asm *p, char **line, int size)
{
    char    *name;
    t_inst  instruction;

    name = ft_strndup(*line, size);
	init_instruction(p, &instruction, 0);
    if ((instruction.pos = is_instruction(p, name)) < 0)
        {
            printf("no instruction index\n");
            return ;
        }
    init_instruction(p, &instruction, 1);
    *line += size;
    printf(BLU"%s [%d]\n"RESET, name, instruction.pos);
    skip_whitespaces(p, line);
    printf(BLU "%s\n" RESET, *line);

}
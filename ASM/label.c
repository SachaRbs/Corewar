/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:05:21 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/24 18:05:21 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

t_label     *init_label(char **str)
{
    t_label     *new;
	char		*tmp;

	tmp = *str;
    while (**str != LABEL_CHAR)
        (*str)++;
	if (tmp == *str)
        ft_error("LABEL SIZE INVALID");
	if (!(new = malloc(sizeof(t_label))))
        return (NULL);
    if (!(new->name = ft_strndup(tmp, *str - tmp)))
        return (NULL);
	(*str)++;											// skip ":"
	printf(GRN"[%s]\n"RESET, new->name);
    new->next = NULL;
    return (new);
}

t_label     *add_label(t_asm *p, char **str)
{
    t_label     *new;
    t_label     *tmp;

    if (!(new = init_label(str)))
        return (NULL);
	if (!p->labels)
		p->labels = new;
	else
	{
		tmp = p->labels;
		while (tmp->next)
		{
			if (!(ft_strcmp(tmp->name, new->name)))
				ft_error("DUPLICATE LABEL");
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return (new);
}

int		is_labelname(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_islower(str[i]) || !ft_isdigit(str[i]) || str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	print_labels(t_label *head)
{
	t_label *tmp;

	tmp = head;
	while (tmp)
	{
		printf(RED"%s\n"RESET, tmp->name);
		tmp = tmp->next;
	}
}
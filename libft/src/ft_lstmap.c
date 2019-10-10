/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:50 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:50 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*newlist;
	t_list		*current;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		new = f(lst);
		if (!newlist)
			newlist = new;
		else
			current->next = new;
		current = new;
		lst = lst->next;
	}
	return (newlist);
}

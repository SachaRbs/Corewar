/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:20:49 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/10 18:20:49 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nxtlst;

	list = *alst;
	while (list)
	{
		nxtlst = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxtlst;
	}
	*alst = NULL;
}

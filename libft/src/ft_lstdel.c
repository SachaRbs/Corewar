/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 09:55:51 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:14:46 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:54:03 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:10:24 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

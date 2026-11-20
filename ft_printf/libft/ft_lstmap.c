/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:15:59 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 18:44:17 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Iterates through the list ’lst’, applies the function ’f’ to each node’s 
content, and creates a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to delete the content of a 
node if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new_lst;
	t_list	*lst_new_item;
	void	*new_content;

	lst_new_lst = NULL;
	if (!f || !del || !lst)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		lst_new_item = ft_lstnew(new_content);
		if (lst_new_item == NULL)
		{
			del(new_content);
			ft_lstclear(&lst_new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new_lst, lst_new_item);
		lst = lst->next;
	}
	return (lst_new_lst);
}

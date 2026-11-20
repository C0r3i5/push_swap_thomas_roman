/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:03:56 by twalter           #+#    #+#             */
/*   Updated: 2026/10/30 07:25:32 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Iterates through the list ’lst’ and applies the function ’f’ to the content 
of each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = (t_list *)lst->next;
	}
}

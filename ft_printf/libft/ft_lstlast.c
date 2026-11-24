/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:38:02 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 18:38:10 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Returns the last node of the list.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
	{
		lst = (t_list *)lst->next;
	}
	return (lst);
}

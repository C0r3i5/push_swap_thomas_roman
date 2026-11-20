/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:59:32 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:30:27 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Takes a node as parameter and frees its content using the function ’del’. 
Free the node itself but does NOT free the next node.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:46:16 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 18:35:28 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Counts the number of nodes in the list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i_size;

	if (!lst)
		return (0);
	i_size = 0;
	while (lst)
	{
		lst = (t_list *)lst->next;
		i_size++;
	}
	return (i_size);
}

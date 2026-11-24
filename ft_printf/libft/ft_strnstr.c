/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:26:15 by twalter           #+#    #+#             */
/*   Updated: 2026/10/30 07:26:12 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len characters
     are searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i] != '\0')
	{
		while (little[j] != '\0' && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *) big + i);
		j = 0;
		i++;
	}
	return (NULL);
}

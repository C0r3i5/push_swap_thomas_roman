/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:09:46 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 18:30:47 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Copies n bytes from memory area src to memory
area dest.  The memory areas may overlap: copying takes place as though
the  bytes in src are first copied into a temporary array that does not
overlap src or dest, and the bytes are then copied from  the  temporary
array to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*idest;
	unsigned char	*isrc;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	idest = (unsigned char *) dest;
	isrc = (unsigned char *) src;
	if (src > dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			n--;
			idest[n] = isrc[n];
		}
	}
	return (dest);
}

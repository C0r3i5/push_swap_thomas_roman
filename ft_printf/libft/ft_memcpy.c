/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:17:27 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:44:02 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  memcpy()  function  copies  n bytes from memory area src to memory
area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
memory areas do overlap.

*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*idest;
	unsigned char	*isrc;

	if (dest == src)
		return (dest);
	idest = (unsigned char *) dest;
	isrc = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		idest[i] = isrc[i];
		i++;
	}
	return (idest);
}

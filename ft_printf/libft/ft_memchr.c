/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:51:33 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 19:34:28 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  memchr()  function  scans  the  initial n bytes of the memory area
pointed to by s for the first instance of c.  Both c and the  bytes  of
the memory area pointed to by s are interpreted as unsigned char.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	cc;

	i = 0;
	ch = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (ch[i] == cc)
			return (ch + i);
		i++;
	}
	return (NULL);
}

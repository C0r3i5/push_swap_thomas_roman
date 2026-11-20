/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:33:51 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:43:18 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  memset()  function  fills  the  first  n  bytes of the memory area
pointed to by s with the constant byte c.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	ch = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ch[i] = c;
		i = i + 1;
	}
	return (s);
}

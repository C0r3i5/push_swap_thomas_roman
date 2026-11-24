/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:11:38 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:46:09 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  memcmp()  function compares the first n bytes (each interpreted as
unsigned char) of the memory areas s1 and s2
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	ch1 = (unsigned char *) s1;
	ch2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}

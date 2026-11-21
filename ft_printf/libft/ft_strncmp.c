/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:14:16 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:45:54 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  strcmp()  function compares the two strings s1 and s2. 
The comparison is done using unsigned characters.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	while (((ch1[i] != '\0') || (ch2[i] != '\0')) && (i < n))
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:13:52 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 19:15:16 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered
 part of the string; therefore if c is ‘\0’, the functions locate the 
 terminating ‘\0’.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != (char)c)
	{
		if (s[idx] == '\0')
			return (NULL);
		idx++;
	}
	return ((char *) &s[idx]);
}

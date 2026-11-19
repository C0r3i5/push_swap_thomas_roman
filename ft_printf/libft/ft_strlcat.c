/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:21:06 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 18:02:30 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The strlcat() function appends the NUL-terminated string src to the end
     of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
     nating the result.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	i_len_src;

	i = 0;
	j = 0;
	i_len_src = ft_strlen(src);
	while ((i < size) && (dst[i] != '\0'))
		i++;
	if (i == size)
		return (i + i_len_src);
	while ((src[j] != '\0') && (i < size - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (i_len_src + i - j);
}

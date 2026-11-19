/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:06:06 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:46:39 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  strdup() function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new string  is  obtained  with
       malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i_len;
	char	*ptr;

	i_len = ft_strlen(s) + 1;
	ptr = malloc(i_len);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, i_len);
	return (ptr);
}

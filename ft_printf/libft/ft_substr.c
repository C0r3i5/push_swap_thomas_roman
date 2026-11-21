/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:35:39 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 19:25:59 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Allocates memory (using malloc(3)) and returns a substring from the string ’s’.
The substring starts at index ’start’ and has a maximum length of ’len’. 
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_str_len;

	if (s == NULL)
		return (NULL);
	s_str_len = ft_strlen(s);
	if (start >= s_str_len)
		return (ft_strdup(""));
	if (len > s_str_len - start)
		len = s_str_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, &s[start], len);
	ptr[len] = '\0';
	return (ptr);
}

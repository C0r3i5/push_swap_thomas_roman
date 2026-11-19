/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:28:25 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:49:43 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Allocates memory (using malloc(3)) and returns a new string, which is the 
result of concatenating ’s1’ and ’s2’. 
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i_len_s1;
	size_t	i_len_s2;

	if (!s1 || !s2)
		return (NULL);
	i_len_s1 = ft_strlen(s1);
	i_len_s2 = ft_strlen(s2);
	ptr = malloc(i_len_s1 + i_len_s2 + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, i_len_s1);
	ft_memcpy(&ptr[i_len_s1], s2, i_len_s2);
	ptr[i_len_s1 + i_len_s2] = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:53:18 by twalter           #+#    #+#             */
/*   Updated: 2026/10/23 14:48:31 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters 
from ’set’ removed from the beginning and the end.
 */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_len_s1;
	size_t	start;
	size_t	stop;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i_len_s1 = ft_strlen(s1);
	if (i_len_s1 == 0)
		return (ft_strdup(s1));
	start = 0;
	stop = i_len_s1 - 1;
	while ((s1[start] != '\0') && (ft_strchr(set, s1[start])))
		start++;
	while ((s1[stop] != '\0') && (ft_strchr(set, s1[stop])) && (stop > start))
		stop--;
	return (ft_substr(s1, start, stop - start + 1));
}

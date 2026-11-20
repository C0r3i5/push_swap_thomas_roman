/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:44:59 by twalter           #+#    #+#             */
/*   Updated: 2026/11/02 16:24:50 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The strlen() function calculates the length of the string pointed to by
       s, excluding the terminating null byte ('\0').
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	return (i);
}

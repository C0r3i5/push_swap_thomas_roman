/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:06:29 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 14:58:56 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
explicit_bzero - zero a byte string
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	ch = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ch[i] = '\0';
		i = i + 1;
	}
}

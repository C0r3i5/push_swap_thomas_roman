/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:18:53 by twalter           #+#    #+#             */
/*   Updated: 2026/10/23 15:02:41 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
checks whether c is a 7-bit unsigned char value that fits into
the ASCII character set.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

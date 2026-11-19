/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:01:24 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 13:37:09 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
If c is a lowercase letter, toupper() returns its uppercase equivalent
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}

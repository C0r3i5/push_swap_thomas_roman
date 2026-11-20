/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:10:27 by twalter           #+#    #+#             */
/*   Updated: 2026/10/23 15:13:14 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
If c is an uppercase letter, tolower() returns  its  lowercase  equivalent
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	else
		return (c);
}

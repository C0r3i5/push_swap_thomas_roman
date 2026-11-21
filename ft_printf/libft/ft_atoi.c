/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:13:22 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 20:05:41 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
convert a string to an integer
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	i_ret;
	int		i_neg;

	i_ret = 0;
	i_neg = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		i_neg = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		i_ret = (i_ret * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)(i_ret * i_neg));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:38:59 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 19:56:49 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Allocates memory (using malloc(3)) and returns a string representing the 
integer received as an argument. Negative numbers must be handled.
*/

#include "libft.h"

static size_t	ft_countdigits(long n)
{
	size_t	i_digits;

	i_digits = 0;
	if (n <= 0)
		i_digits = 1;
	while (n != 0)
	{
		i_digits++;
		n = n / 10;
	}
	return (i_digits);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	l_n;

	l_n = n;
	i = ft_countdigits(l_n);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	if (l_n == 0)
		ptr[0] = '0';
	if (l_n < 0)
	{
		l_n = -l_n;
		ptr[0] = '-';
	}
	while (l_n > 0)
	{
		ptr[--i] = (l_n % 10) + '0';
		l_n = l_n / 10;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 08:44:50 by twalter           #+#    #+#             */
/*   Updated: 2026/11/10 07:44:44 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_convert(unsigned long n, char *base_string)
{
	int				counter_char;
	unsigned long	base;
	int				i_temp;

	counter_char = 0;
	i_temp = 0;
	base = ft_strlen(base_string);
	if (n >= base)
		i_temp = (ft_convert(n / base, base_string));
	if (i_temp == -1)
		return (-1);
	counter_char += i_temp;
	i_temp = write(1, &base_string[n % base], 1);
	if (i_temp == -1)
		return (-1);
	counter_char += i_temp;
	return (counter_char);
}

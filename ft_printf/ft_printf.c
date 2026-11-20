/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 08:00:42 by twalter           #+#    #+#             */
/*   Updated: 2026/11/10 08:01:49 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_printf_string(char *c_string)
{
	int	i_temp;

	if (c_string == NULL)
		c_string = "(null)";
	i_temp = write(1, c_string, ft_strlen(c_string));
	if (i_temp == -1)
		return (-1);
	return (i_temp);
}

static int	ft_printf_pointer(void *ptr)
{
	int	cc;
	int	i_temp;

	if (ptr == NULL)
	{
		i_temp = write(1, "(nil)", 5);
		if (i_temp == -1)
			return (-1);
		return (i_temp);
	}
	i_temp = write(1, "0x", 2);
	if (i_temp == -1)
		return (-1);
	cc = i_temp;
	i_temp = ft_convert((unsigned long)ptr, "0123456789abcdef");
	if (i_temp == -1)
		return (-1);
	cc = cc + i_temp;
	return (cc);
}

static int	ft_printf_int(int n)
{
	int		cc;
	long	n_long;
	int		i_temp;

	cc = 0;
	n_long = n;
	if (n_long < 0)
	{
		i_temp = write(1, "-", 1);
		if (i_temp == -1)
			return (-1);
		cc += i_temp;
		n_long = -n_long;
	}
	i_temp = ft_convert(n_long, "0123456789");
	if (i_temp == -1)
		return (-1);
	cc = cc + i_temp;
	return (cc);
}

static int	ft_char_switch(char c, va_list *arg_ptr)
{
	int	cc;
	int	c_temp;

	cc = 0;
	if (c == 'c')
	{
		c_temp = va_arg(*arg_ptr, int);
		cc = write (1, &c_temp, 1);
	}
	else if (c == 's')
		cc = ft_printf_string(va_arg(*arg_ptr, char *));
	else if (c == 'p')
		cc = ft_printf_pointer(va_arg(*arg_ptr, void *));
	else if (c == 'd' || c == 'i')
		cc = ft_printf_int(va_arg(*arg_ptr, int));
	else if (c == 'u')
		cc = ft_convert(va_arg(*arg_ptr, unsigned int), "0123456789");
	else if (c == 'x')
		cc = ft_convert(va_arg(*arg_ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		cc = ft_convert(va_arg(*arg_ptr, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		cc = write (1, "%", 1);
	return (cc);
}

int	ft_printf(const char *arguments, ...)
{
	va_list	arg_ptr;
	int		counter_char;
	int		i_temp;

	va_start(arg_ptr, arguments);
	counter_char = 0;
	while (*arguments != '\0')
	{
		if (*arguments == '%' && (*(arguments + 1) != '\0'))
			i_temp = ft_char_switch(*(++arguments), &arg_ptr);
		else
			i_temp = write(1, arguments, 1);
		if (i_temp == -1)
		{
			va_end(arg_ptr);
			return (-1);
		}
		counter_char += i_temp;
		arguments++;
	}
	va_end(arg_ptr);
	return (counter_char);
}

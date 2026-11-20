/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 09:29:43 by twalter           #+#    #+#             */
/*   Updated: 2026/10/23 14:52:13 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Outputs the character ’c’ to the specified file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

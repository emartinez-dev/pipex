/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:33:46 by franmart          #+#    #+#             */
/*   Updated: 2022/10/16 12:52:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long ptr)
{
	int		len;

	len = 1;
	while (ptr / 16)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_ptr(unsigned long long ptr, int fd)
{
	unsigned int	c;

	if (ptr / 16 > 0)
	{
		ft_putnbr_ptr(ptr / 16, fd);
	}
	if (ptr % 16 < 10)
		c = ptr % 16 + 48;
	if (ptr % 16 > 9 && ptr % 16 < 17)
		c = ptr % 16 + 87;
	ft_putchar_fd(c, fd);
}

int	ft_parse_ptr(unsigned long long ptr)
{
	int	len;

	len = ft_ptr_len(ptr) + 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_ptr(ptr, 1);
	return (len);
}

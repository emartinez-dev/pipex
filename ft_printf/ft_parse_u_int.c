/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:35:15 by franmart          #+#    #+#             */
/*   Updated: 2022/10/16 13:27:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	int	c;

	if (n / 10 > 0)
		ft_putnbr_uint_fd(n / 10, fd);
	c = n % 10 + 48;
	ft_putchar_fd(c, fd);
}

int	ft_parse_u_int(unsigned int u)
{
	int		len;
	char	*str;

	str = ft_itoa(u);
	len = ft_strlen(str);
	free(str);
	ft_putnbr_uint_fd(u, 1);
	return (len);
}

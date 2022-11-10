/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:34:53 by franmart          #+#    #+#             */
/*   Updated: 2022/11/07 18:21:03 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_unsigned(unsigned long n, char *base, int *chars)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n / base_len > 0)
		ft_putnbr_base_unsigned(n / base_len, base, chars);
	c = base[n % base_len];
	*chars += 1;
	ft_putchar(c);
}

void	ft_putnbr_base_signed(long n, char *base, int *chars)
{
	int		c;
	size_t	base_len;

	base_len = ft_len(base);
	if (n < 0)
	{
		*chars += 1;
		ft_putchar('-');
		n *= -1;
	}
	if (n / base_len > 0)
		ft_putnbr_base_signed(n / base_len, base, chars);
	c = base[n % base_len];
	*chars += 1;
	ft_putchar(c);
}

int	ft_parse_nbr(long n, char *base, char flag)
{
	int	i;

	i = 0;
	if (flag == 'p')
	{
		i += ft_parse_str("0x");
	}
	if (flag == 'x' || flag == 'X' || flag == 'u' || flag == 'p')
		ft_putnbr_base_unsigned(n, base, &i);
	else
		ft_putnbr_base_signed(n, base, &i);
	return (i);
}
/*
int	main(void)
{
	long 	n;
	int		i;
	char	*base;

	base = "0123456789abcdef";
	n = -1;
	i = ft_parse_nbr(n, base, 'p');
	printf("\n%d\n", i);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:51:50 by franmart          #+#    #+#             */
/*   Updated: 2022/10/13 21:01:06 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_lastdigit(int n)
{
	while (n > 9)
		n = n % 10;
	return (n);
}

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	result = nb;
	i = 1;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

char	*ft_itoa(long int n)
{
	int		n_len;
	char	*str;
	int		stop;

	stop = 0;
	n_len = ft_intlen(n);
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		stop = 1;
	}
	str[n_len] = '\0';
	while (n_len > stop)
	{
		str[n_len - 1] = ft_lastdigit(n) + '0';
		n /= 10;
		n_len--;
	}
	return (str);
}

/*
int	main(int argc, char **argv)
{
	int	n;

	n = 0;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		printf("\n\n\nN original: %d. Mi N: %s\n", n, ft_itoa(n));
	}
	return (0);
}
*/

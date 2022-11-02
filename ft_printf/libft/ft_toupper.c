/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:57 by franmart          #+#    #+#             */
/*   Updated: 2022/09/25 16:29:03 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	int		testing;

	testing = 'z';
	i = ft_toupper(testing);
	j = toupper(testing);
	printf("La mia: %c\nLa buena: %c\n", i, j);
	if (i == j)
		printf("OK!!");
	else
		printf("ERROR!!!");
	return (0);
} */

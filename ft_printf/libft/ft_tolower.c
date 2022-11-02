/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:45 by franmart          #+#    #+#             */
/*   Updated: 2022/09/25 16:28:48 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	int		testing;

	testing = 'Z';
	i = ft_tolower(testing);
	j = tolower(testing);
	printf("La mia: %c\nLa buena: %c\n", i, j);
	if (i == j)
		printf("OK!!");
	else
		printf("ERROR!!!");
	return (0);
} */

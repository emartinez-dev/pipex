/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:24:19 by franmart          #+#    #+#             */
/*   Updated: 2022/09/25 16:31:09 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = c;
		i++;
	}
	return (s);
}

/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int     a;
    int     b;
    void     *i;
    void     *j;
    int     c;
    size_t  n;
    a = 0;
    i = &a;
    b = 0;
    j = &b;
    

    c = 69;
    n = 5;
	ft_memset(i, c, n);
    memset(j, c, n);
    
	printf("La mia: %p\nLa buena: %p\n", i, j);
	if (i != j)
		printf("OK!!");
	else
		printf("ERROR!!!");
	return (0);
}
*/

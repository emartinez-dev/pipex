/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:24:32 by franmart          #+#    #+#             */
/*   Updated: 2022/09/26 17:18:59 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if ((char *)dest > (char *)src)
		while (n-- > 0)
			*(char *)(dest + n) = *(char *)(src + n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

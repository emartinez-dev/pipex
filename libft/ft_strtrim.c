/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:40:08 by franmart          #+#    #+#             */
/*   Updated: 2022/09/29 19:39:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_in_str(char const *str, char const c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_first_pos(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_char_in_str(set, s1[i]))
		i++;
	return (i);
}

int	ft_last_pos(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_char_in_str(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	f_pos;
	size_t	l_pos;

	if (ft_strlen(set) == 0 || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	if (!s1 || !set)
		return (0);
	f_pos = ft_first_pos(s1, set);
	l_pos = ft_last_pos(s1, set) + 1;
	str = ft_substr(s1, f_pos, l_pos - f_pos);
	return (str);
}

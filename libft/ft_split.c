/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:49:10 by franmart          #+#    #+#             */
/*   Updated: 2022/10/20 19:53:42 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	count;
	int				i;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}

unsigned int	ft_next_del_pos(char const *s, char c)
{
	int				i;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (s_len);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	next_del;
	char			**arr_of_str;

	i = 0;
	j = 0;
	arr_of_str = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!arr_of_str)
		return (0);
	next_del = ft_next_del_pos(s, c);
	while (i < ft_strlen(s))
	{
		if (next_del > 0)
			arr_of_str[j++] = ft_substr(s, i, next_del);
		i += next_del + 1;
		if (i < ft_strlen(s))
			next_del = ft_next_del_pos(s + i, c);
	}
	arr_of_str[j] = 0;
	return (arr_of_str);
}

/*
int	main(void)
{
	char *str = NULL;
	char **arr;
	int	j;

	j = 0;
	arr = ft_split(str, 0);
	
	while (arr[j] != 0)
	{
		printf("%s", arr[j]);
		j++;
	}
	return (0);
}
*/

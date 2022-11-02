/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:21 by franmart          #+#    #+#             */
/*   Updated: 2022/10/16 12:36:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_parse_char(char c);
int		ft_parse_str(char *str);
int		ft_parse_ptr(unsigned long long ptr);
int		ft_parse_int(int i);
int		ft_parse_u_int(unsigned int u);
int		ft_parse_hex(unsigned int hex, char upper);
void	ft_putnbr_hex(unsigned int n, int fd, char upper);
int		ft_hex_len(unsigned int hex);

#	endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:21 by franmart          #+#    #+#             */
/*   Updated: 2022/11/07 18:14:25 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(char const *str, ...);
int				ft_parse_char(char c);
int				ft_parse_str(char *str);
void			ft_putchar_fd(char c, int fd);
int				ft_parse_nbr(long n, char *base, char flag);
unsigned int	ft_len(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *s);

#	endif

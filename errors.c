/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:37:42 by franmart          #+#    #+#             */
/*   Updated: 2022/11/15 21:05:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prints an error message and exits the program
 * 
 * @param err_str error message
 * @param cmd command or file that caused the error
 */
void	error_exec(char *err_str, char *cmd)
{
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

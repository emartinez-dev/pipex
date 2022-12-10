/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:37:42 by franmart          #+#    #+#             */
/*   Updated: 2022/11/28 19:05:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prints an error message but don't exit the program
 * 
 * @param err_str error message
 * @param cmd command or file that caused the error
 */
void	print_error(char *err_str, char *cmd)
{
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

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

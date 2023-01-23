/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:07:54 by franmart          #+#    #+#             */
/*   Updated: 2023/01/23 10:29:39 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# define READ_MODE 0
# define WRITE_MODE 1

# include "../lib/libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

# include <errno.h>
# include <string.h>

char	*ft_find_executable(char *cmd, char **env);
void	close_pipes(int *fd);
void	check_args(int argc);
int		ft_open_file(char *filename, int mode);
void	print_error(char *err_str, char *cmd);
void	error_exec(char *err_str, char *cmd);

#endif

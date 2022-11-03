/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:07:54 by franmart          #+#    #+#             */
/*   Updated: 2022/11/03 17:29:49 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# define READ_MODE 0
# define WRITE_MODE 1
# define APPEND_MODE 2

# include "ft_printf/ft_printf.h"
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

#endif

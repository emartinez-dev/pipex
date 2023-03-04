/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:50:35 by franmart          #+#    #+#             */
/*   Updated: 2023/03/04 11:27:31 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_open_file(char *filename, int mode)
{
	int	fd;

	if (mode == READ_MODE)
		fd = open(filename, O_RDONLY, 0777);
	else if (mode == WRITE_MODE)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = -1;
	if (fd == -1)
		error_exec("pipex: file not found: ", filename);
	return (fd);
}

char	*cmd_in_path(char *cmd, char *path)
{
	char	*file;
	char	*check_path;

	if (!path || !cmd)
		return (0);
	check_path = ft_strjoin("/", path);
	file = ft_strjoin(cmd, check_path);
	free(check_path);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (0);
}

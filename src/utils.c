/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:50:35 by franmart          #+#    #+#             */
/*   Updated: 2023/01/23 19:58:50 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_open_file(char *filename, int mode)
{
	int	fd;

	if (mode == READ_MODE)
		fd = open(filename, O_RDONLY);
	else if (mode == WRITE_MODE)
		fd = open(filename, O_TRUNC | O_RDWR | O_CREAT, 0644);
	else
		fd = -1;
	if (fd == -1)
		error_exec("pipex: file not found: ", filename);
	return (fd);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->n_pipes)
	{
		close(pipex->pipes_fd[i][READ_END]);
		close(pipex->pipes_fd[i][WRITE_END]);
	}
}

char	*cmd_in_path(char *cmd, char *path)
{
	char	*file;

	path = ft_strjoin("/", path);
	file = ft_strjoin(cmd, path);
	free(path);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (0);
}

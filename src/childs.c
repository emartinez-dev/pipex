/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:08:24 by franmart          #+#    #+#             */
/*   Updated: 2023/01/31 13:27:59 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exec_child(t_pipex *pipex, int child)
{
	if (child == 0 && pipex->heredoc)
		here_doc(pipex);
	else if (child == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipes_fd[child][WRITE_END], STDOUT_FILENO);
		close(pipex->pipes_fd[child][READ_END]);
	}
	else if (child == pipex->n_cmds - 1)
	{
		dup2(pipex->outfile, STDOUT_FILENO);
		dup2(pipex->pipes_fd[child - 1][READ_END], STDIN_FILENO);
		close(pipex->pipes_fd[child - 1][WRITE_END]);
	}
	else
	{
		dup2(pipex->pipes_fd[child - 1][READ_END], STDIN_FILENO);
		close(pipex->pipes_fd[child - 1][WRITE_END]);
		dup2(pipex->pipes_fd[child][WRITE_END], STDOUT_FILENO);
		close(pipex->pipes_fd[child][READ_END]);
	}
	execve(pipex->cmds[child].exec, pipex->cmds[child].args, pipex->env);
}

void	here_doc(t_pipex *pipex)
{
	char	*line;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		close(pipex->pipes_fd[0][READ_END]);
		line = ft_gnl(STDIN_FILENO);
		while (line && ft_strncmp(line, pipex->del, ft_strlen(line)) != 0)
		{
			write(pipex->pipes_fd[0][WRITE_END], line, ft_strlen(line));
			free(line);
			line = ft_gnl(STDIN_FILENO);
		}
		free(line);
	}
	else
	{
		close(pipex->pipes_fd[0][WRITE_END]);
		dup2(pipex->pipes_fd[0][READ_END], STDIN_FILENO);
		waitpid(pid, &pipex->status[0], 0);
	}
}
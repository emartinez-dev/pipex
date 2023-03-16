/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:08:24 by franmart          #+#    #+#             */
/*   Updated: 2023/03/16 08:22:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exec_child(t_pipex *pipex, int child)
{
	if (child == 0)
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
	if (pipex->cmds[child].exec)
		execve(pipex->cmds[child].exec, pipex->cmds[child].args, pipex->env);
}

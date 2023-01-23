/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:02:22 by franmart          #+#    #+#             */
/*   Updated: 2023/01/23 20:59:10 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	wait_childs(t_pipex *pipex)
{
	int	child;

	child = -1;
	while (++child < pipex->n_cmds)
	{
		waitpid(pipex->pids[child], &pipex->status[child], 0);
		if (WIFEXITED(pipex->status[child]))
			return (WEXITSTATUS(pipex->status[child]));
	}
	return (0);
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

void	free_everything(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->n_pipes)
		free(pipex->pipes_fd[i]);
	i = -1;
	while (++i < pipex->n_cmds)
	{
		free(pipex->cmds[i].exec);
		ft_free_array(pipex->cmds[i].args);
	}
	free(pipex->cmds);
	free(pipex->pipes_fd);
	free(pipex->pids);
	free(pipex->status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:03:53 by franmart          #+#    #+#             */
/*   Updated: 2023/01/23 19:57:17 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		child;

	child = -1;
	if (check_args(argc))
		return (1);
	init_pipex(&pipex, argc, argv, env);
	while (++child < pipex.n_cmds)
	{
		pipex.pids[child] = fork();
		if (pipex.pids[child] == 0)
			exec_child(&pipex, child);
		else if (pipex.pids[child] == -1)
			return (1);
	}
	close_pipes(&pipex);
	child = -1;
	while (++child < pipex.n_cmds)
	{
		waitpid(pipex.pids[child], &pipex.status[child], 0);
		if (WIFEXITED(pipex.status[child]))
			return (WEXITSTATUS(pipex.status[child]));
	}
	return (0);
}
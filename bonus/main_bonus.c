/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:03:53 by franmart          #+#    #+#             */
/*   Updated: 2023/03/16 08:22:25 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		child;
	int		status;

	child = -1;
	if (check_args(argc, env))
		return (1);
	if (init_pipex(&pipex, argc, argv, env))
		return (2);
	while (++child < pipex.n_cmds)
	{
		if (!pipex.cmds[child].exec)
			print_error("pipex: command not found:", argv[++child + 1]);
		pipex.pids[child] = fork();
		if (pipex.pids[child] == 0)
			exec_child(&pipex, child);
		else if (pipex.pids[child] == -1)
			return (3);
	}
	close_pipes(&pipex);
	status = wait_childs(&pipex);
	free_everything(&pipex);
	return (status);
}

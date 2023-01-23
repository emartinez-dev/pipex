/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:22:04 by franmart          #+#    #+#             */
/*   Updated: 2023/01/23 17:02:56 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	int		n_cmds;
	char	**command;

	n_cmds = -1;
	pipex->infile = ft_open_file(argv[1], READ_MODE);
	pipex->outfile = ft_open_file(argv[argc - 1], WRITE_MODE);
	pipex->cmds = ft_calloc(sizeof(t_cmd), argc - 3);
	while (++n_cmds < argc - 3)
	{
		command = ft_split(argv[n_cmds + 2], ' ');
		pipex->cmds[n_cmds].exec = ft_find_executable(command[0], env);
		pipex->cmds[n_cmds].args = ft_find_args(argv[n_cmds + 2]);
		pipex->cmds[n_cmds].env = env;
		ft_free_array(command);
	}
	pipex->n_cmds = n_cmds;
	pipex->n_pipes = n_cmds - 1;
	pipex->pids = ft_calloc(sizeof(int), pipex->n_cmds);
	pipex->status = ft_calloc(sizeof(int), pipex->n_cmds);
	return (0);
}

int	init_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->pipes_fd = ft_calloc(sizeof(int *), pipex->n_pipes);
	while (++i < pipex->n_pipes)
	{
		pipex->pipes_fd[i] = ft_calloc(sizeof(int), 2);
		if (pipe(pipex->pipes_fd[i]) == -1)
			return (1);
	}
	return (0);
}

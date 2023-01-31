/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:22:04 by franmart          #+#    #+#             */
/*   Updated: 2023/01/31 13:36:14 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->heredoc = ft_strncmp(argv[1], HERE_DOC, ft_strlen(argv[1])) == 0;
	pipex->env = env;
	if (pipex->heredoc)
	{
		pipex->del = ft_strjoin(argv[2], "\n");
		pipex->infile = 666;
		pipex->outfile = ft_open_file(argv[argc - 1], APPEND_MODE);
	}
	else
	{
		pipex->infile = ft_open_file(argv[1], READ_MODE);
		pipex->outfile = ft_open_file(argv[argc - 1], WRITE_MODE);
	}
	if (pipex->infile == -1 || pipex->outfile == -1)
		return (1);
	pipex->n_cmds = argc - 3;
	pipex->n_pipes = pipex->n_cmds - 1;
	pipex->pids = ft_calloc(sizeof(int), pipex->n_cmds);
	pipex->status = ft_calloc(sizeof(int), pipex->n_cmds);
	if (find_commands(pipex, argv, env))
		return (2);
	if (create_pipes(pipex))
		return (3);
	return (0);
}

int	find_commands(t_pipex *pipex, char **argv, char **env)
{
	int		i;
	char	**command;

	i = -1;
	pipex->cmds = ft_calloc(sizeof(t_cmd), pipex->n_cmds);
	while (++i < pipex->n_cmds)
	{
		command = ft_split(argv[i + 2], ' ');
		pipex->cmds[i].exec = ft_find_executable(command[0], env);
		ft_free_array(command);
		pipex->cmds[i].args = ft_find_args(argv[i + 2]);
	}
	return (0);
}

int	create_pipes(t_pipex *pipex)
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

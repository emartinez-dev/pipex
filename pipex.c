/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:03:53 by franmart          #+#    #+#             */
/*   Updated: 2022/11/03 17:41:00 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, int pipe_fd[2], char **environ)
{
	int		infile;
	char	**args;
	char	*exec;

	args = ft_split(argv[2], ' ');
	exec = ft_find_executable(args[0], environ);
	if (!exec)
	{
		ft_printf("pipex: command not found: %s\n", args[0]);
		exit(0);
	}
	infile = ft_open_file(argv[1], READ_MODE);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close_pipes(pipe_fd);
	close(infile);
	execve(exec, args, environ);
}

void	second_child(char **argv, int pipe_fd[2], char **environ)
{
	int		outfile;
	char	**args;
	char	*exec;

	args = ft_split(argv[3], ' ');
	exec = ft_find_executable(args[0], environ);
	if (!exec)
	{
		ft_printf("pipex: command not found: %s\n", args[0]);
		exit(0);
	}
	outfile = ft_open_file(argv[4], WRITE_MODE);
	dup2(pipe_fd[READ_END], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_pipes(pipe_fd);
	close(outfile);
	execve(exec, args, environ);
}

int	main(int argc, char **argv, char **environ)
{
	int	pid1;
	int	pid2;
	int	pipe_fd[2];

	check_args(argc);
	if (pipe(pipe_fd) == -1)
		perror("Error");
	pid1 = fork();
	if (pid1 == -1)
		perror("Error");
	if (pid1 == 0)
		first_child(argv, pipe_fd, environ);
	pid2 = fork();
	if (pid2 == -1)
		perror("Error");
	if (pid2 == 0)
		second_child(argv, pipe_fd, environ);
	close_pipes(pipe_fd);
	wait(NULL);
	return (0);
}

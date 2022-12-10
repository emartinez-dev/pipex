/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:03:53 by franmart          #+#    #+#             */
/*   Updated: 2022/11/30 21:10:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TODO: trabajar los prints del STDERROR
TODO: cambiar lo del waitpid a ver si se puede hacer sin eso 
*/

/* 
 * Ni idea de si esto se puede hacer con WIFEXITED, 
 * creo que solo con waitpid también se pueden ver los códigos de salida
 */

#include "pipex.h"

/**
 * @brief Commands that the first child will execute
 * 
 * @param argv first command with its arguments
 * @param pipe_fd pipe file descriptor
 * @param infile input file descriptor
 * @param environ environment variables
 */
void	first_child(char **argv, int pipe_fd[2], int infile, char **environ)
{
	char	**args;
	char	*exec;
	int		i;

	i = 0;
	args = ft_split(argv[2], ' ');
	exec = ft_find_executable(args[0], environ);
	if (!exec)
	{
		print_error("pipex: command not found: ", args[0]);
		free_array(args);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close_pipes(pipe_fd);
	execve(exec, args, environ);
}

/**
 * @brief Commands that the second child will execute
 * 
 * @param argv second command with its arguments
 * @param pipe_fd pipe file descriptor
 * @param outfile output file descriptor
 * @param environ environment variables
 */
void	second_child(char **argv, int pipe_fd[2], int outfile, char **environ)
{
	char	**args;
	char	*exec;
	int		i;

	i = 0;
	args = ft_split(argv[3], ' ');
	exec = ft_find_executable(args[0], environ);
	if (!exec)
	{
		print_error("pipex: command not found: ", args[0]);
		free_array(args);
		exit(1);
	}
	dup2(pipe_fd[READ_END], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_pipes(pipe_fd);
	execve(exec, args, environ);
}

int	main(int argc, char **argv, char **environ)
{
	int	pipe_fd[2];
	int	fds[2];
	int	pid[2];
	int	status[2];

	check_args(argc);
	fds[0] = ft_open_file(argv[1], READ_MODE);
	fds[1] = ft_open_file(argv[argc - 1], WRITE_MODE);
	if (pipe(pipe_fd) == -1)
		perror("Pipe error\n");
	pid[0] = fork();
	if (pid[0] == 0)
		first_child(argv, pipe_fd, fds[0], environ);
	pid[1] = fork();
	if (pid[1] == 0)
		second_child(argv, pipe_fd, fds[1], environ);
	close_pipes(pipe_fd);
	waitpid(pid[0], &status[0], 0);
	if (WIFEXITED(status[0]))
		return (WEXITSTATUS(status[0]));
	waitpid(pid[1], &status[1], 0);
	if (WIFEXITED(status[1]))
		return (WEXITSTATUS(status[1]));
	return (0);
}

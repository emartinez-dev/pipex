/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:03:53 by franmart          #+#    #+#             */
/*   Updated: 2022/11/02 21:47:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, int pipe_fd[2])
{
	int	infile;

	infile = ft_open_file(argv[1], READ_MODE);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);
	close(infile);
	execlp("/usr/bin/ls", "ls", "-l", NULL);
}

void	second_child(char **argv, int pipe_fd[2])
{
	int	outfile;

	outfile = ft_open_file(argv[4], WRITE_MODE);
	dup2(pipe_fd[READ_END], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);
	close(outfile);
	execlp("/usr/bin/wc", "wc", "-l", NULL);
}

int	main(int argc, char **argv, char **environ)
{
	int	pid;
	int	outfile;
	int	pipe_fd[2];

	if (argc != 5)
		return 1;
	if (pipe(pipe_fd) == -1)
		return 1;
	outfile = ft_open_file(argv[4], WRITE_MODE);
	pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0)
		first_child(argv, pipe_fd);
	else
	{
		wait(NULL);
		pid = fork();
		if (pid == -1)
			return 1;
		if (pid == 0)
			second_child(argv, pipe_fd);
		else
		{
			close(pipe_fd[READ_END]);
			close(pipe_fd[WRITE_END]);
			wait(NULL);
		}
	}
	return 0;
}

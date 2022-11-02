/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:17:13 by franmart          #+#    #+#             */
/*   Updated: 2022/11/02 18:15:06 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	swap_file(char *filename, int old_fd, int mode)
{
	int	can_read;
	int	file_fd;

	can_read = access(filename, F_OK);
	if (can_read == -1)
		return -1;
	file_fd = open(filename, mode);
	if (file_fd == -1)
		return -1;
	dup2(file_fd, old_fd);
	return file_fd;
}

int	main(void)
{
	int	pid;
	int	pipe_fd[2];
	int	file_fd;

	if (pipe(pipe_fd) == -1)
		return 1;
	// swap el stdin por el archivo "infile"
	file_fd = open("outfile", O_WRONLY | O_CREAT, 0666);
	ft_printf("File: %d\n", file_fd);
	swap_file("infile", STDIN_FILENO, O_RDONLY);
	pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0)
	{
		// el extremo 0 del pipe ya es el stdin, cerramos los que no vamos a utilizar y ejecutamos el primer comando
		close(pipe_fd[READ_END]);
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
		close(pipe_fd[WRITE_END]);
		execlp("/usr/bin/ls", "ls", "-l", NULL);
	}
	else
	{
		// después de ejecutar el primer comando, abrimos el archivo de outfile y hacemos fork
		wait(NULL);
		pid = fork();
		if (pid == 0)
		{
			// redirigimos el lado de lectura del pipe al stdin para que lo lea el comando nuevo
			dup2(pipe_fd[READ_END], STDIN_FILENO);
			// ERROR -> dup2(file_fd, pipe_fd[WRITE_END]);
			// redirigimos el stdout
			dup2(file_fd, STDOUT_FILENO);
			close(pipe_fd[READ_END]);
			close(pipe_fd[WRITE_END]);
			execlp("/usr/bin/wc", "wc", "-l", NULL);
		}
		else
		{
			close(pipe_fd[WRITE_END]);
			close(pipe_fd[READ_END]);
			close(file_fd);
			// por qué no escribe al puto archivo???????// RESPUESTA: porque el pipe_fd se sobreescribe, hay que
			// // redirigir la salida del stdout otra vez,
			// pipe[WRITE_END] no está haciendo nada!!!!!
			// ERR: dup2(file_fd, pipe_fd[WRITE_END]);
			// OK:	---> dup2(file_fd, STDOUT_FILENO);
			wait(NULL);
		}
	}
	return (0);
}

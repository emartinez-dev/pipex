/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:50:35 by franmart          #+#    #+#             */
/*   Updated: 2022/11/28 17:36:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Opens a file in the desired mode and returns the file descriptor
 * 
 * @param filename name of the file to open
 * @param mode mode in which the file will be opened
 * @return int file descriptor
 */
int	ft_open_file(char *filename, int mode)
{
	int	fd;

	if (mode == READ_MODE)
		fd = open(filename, O_RDONLY);
	else if (mode == WRITE_MODE)
		fd = open(filename, O_TRUNC | O_RDWR | O_CREAT, 0644);
	else
		fd = -1;
	if (fd == -1)
		error_exec("pipex: file not found: ", filename);
	return (fd);
}

/**
 * @brief Closes both ends of a pipe
 * 
 * @param fd pipe fd
 */
void	close_pipes(int *fd)
{
	close(fd[READ_END]);
	close(fd[WRITE_END]);
}

/**
 * @brief Checks the number of arguments and exits if it's not correct
 * 
 * @param argc number of arguments
 */
void	check_args(int argc)
{
	if (argc < 5)
		ft_printf("Not enough arguments.");
	if (argc > 5)
		ft_printf("Too many arguments.");
	if (argc != 5)
	{
		ft_printf(" Usage: ./pipex file1 cmd1 cmd1 file2\n");
		exit(1);
	}
}

/**
 * @brief Checks if the full PATH is valid
 * 
 * @param cmd command to check
 * @param path command paths
 * @return char* full path to the command or NULL if it's not valid
 */
char	*is_in_path(char *cmd, char *path)
{
	char	*file;

	path = ft_strjoin("/", path);
	file = ft_strjoin(cmd, path);
	free(path);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (0);
}

/**
 * @brief Checks if a command is in the PATH and returns the full path
 * 
 * @param cmd command to check
 * @param env environment variables
 * @return char* command full path
 */
char	*ft_find_executable(char *cmd, char **env)
{
	int		i;
	int		flag;
	char	**paths;
	char	*file;

	i = -1;
	flag = 0;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i] && flag == 0)
	{
		file = is_in_path(paths[i], cmd);
		if (file)
			flag = 1;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (file);
}

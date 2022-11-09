/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:50:35 by franmart          #+#    #+#             */
/*   Updated: 2022/11/09 17:46:17 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_file(char *filename, int mode)
{
	int	fd;

	if (mode == READ_MODE)
		fd = open(filename, O_RDONLY);
	else if (mode == WRITE_MODE)
		fd = open(filename, O_WRONLY | O_CREAT, 0644);
	else if (mode == APPEND_MODE)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = -1;
	if (fd == -1)
		exit(1);
	return (fd);
}

void	close_pipes(int *fd)
{
	close(fd[READ_END]);
	close(fd[WRITE_END]);
}

void	check_args(int argc)
{
	if (argc < 5)
		ft_printf("Not enough arguments.");
	if (argc > 5)
		ft_printf("Too many arguments.");
	if (argc != 5)
	{
		ft_printf(" Usage: ./pipex file1 cmd1 cmd1 file2\n");
		exit(3);
	}
}

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

/*

// no olvidarme de hacer free una vez tengamos el ejecutable 
int	main(int argc, char **argv, char **environ)
{
	char	*str;

	str = ft_find_executable(argv[1], environ);
	if (str)
		ft_printf("%s\n", str);
	free(str);
	return (0);
}
*/

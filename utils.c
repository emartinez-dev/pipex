/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:50:35 by franmart          #+#    #+#             */
/*   Updated: 2022/11/02 18:53:52 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*is_in_path(char *cmd, char *path)
{
	char	*file;

	if (path[ft_strlen(path)] != '/')
		path = ft_strjoin("/", path);
	file = ft_strjoin(cmd, path);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (0);
}

char	*find_executable(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*file;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(ft_substr(env[i], 5, ft_strlen(env[i])), ':');
		i++;
	}
	i = 0;
	while (paths[i])
	{
		file = is_in_path(paths[i], cmd);
		if (file)
			return (file);
		free(file);
		i++;
	}
	free(paths);
	return (0);
}

int	main(int argc, char **argv, char **environ)
{
	char	*str;

	str = find_executable("ls", environ);
	ft_printf("%s\n", str);
	return (0);
}

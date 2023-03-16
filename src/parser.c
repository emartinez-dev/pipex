/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:32 by franmart          #+#    #+#             */
/*   Updated: 2023/03/16 12:19:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_args(int argc, char **env)
{
	if (!env)
		return (2);
	if (argc != 5)
	{
		ft_printf("You have to introduce just 4 arguments.");
		ft_printf(" Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
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
		file = cmd_in_path(paths[i], cmd);
		if (file)
			flag = 1;
	}
	ft_free_array(paths);
	return (file);
}

char	**ft_find_args(char *cmd)
{
	char	**str;

	if (ft_strchr(cmd, '\"'))
		str = ft_split(cmd, '\"');
	else if (ft_strchr(cmd, '\''))
		str = ft_split(cmd, '\'');
	else if (ft_strchr(cmd, ' '))
		str = ft_split(cmd, ' ');
	else
	{
		str = ft_calloc(2, sizeof(char *));
		str[0] = ft_strdup(cmd);
		str[1] = NULL;
	}
	return (str);
}

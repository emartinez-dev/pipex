/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:07:54 by franmart          #+#    #+#             */
/*   Updated: 2023/01/31 13:28:30 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# define READ_MODE 0
# define WRITE_MODE 1
# define APPEND_MODE 2

# define HERE_DOC "here_doc"

# include "../lib/libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

# include <errno.h>
# include <string.h>

typedef struct s_cmd
{
	char	*exec;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		n_cmds;
	int		n_pipes;
	int		infile;
	int		outfile;
	t_cmd	*cmds;
	int		**pipes_fd;
	int		*pids;
	int		*status;
	char	**env;
	int		heredoc;
	char	*del;
}	t_pipex;

/* init.c */
int		init_pipex(t_pipex *pipex, int argc, char **argv, char **env);
int		find_commands(t_pipex *pipex, char **argv, char **env);
int		create_pipes(t_pipex *pipex);

/* parser.c */
char	*ft_find_executable(char *cmd, char **env);
char	**ft_find_args(char *cmd);
int		check_args(int argc, char **env);

/* childs.c */
void	exec_child(t_pipex *pipex, int child);
void	here_doc(t_pipex *pipex);

/* errors.c */
void	print_error(char *err_str, char *cmd);
void	error_exec(char *err_str, char *cmd);

/* exit.c */
int		wait_childs(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	free_everything(t_pipex *pipex);

/* utils.c */
int		ft_open_file(char *filename, int mode);
char	*cmd_in_path(char *cmd, char *path);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:28:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/19 12:55:26 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_path(char *cmd, char **env)
{
	char	**possible_paths;
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	possible_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (possible_paths[++i])
	{
		temp = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_free_array((void **)possible_paths);
	return (path);
}

void	setup_redirection(t_command *cmd)
{
	int	fd_out;
	int	fd_in;
	int	i;

	if (ft_strncmp(cmd->stdout_redirect, "/dev/stdout", 12))
	{
		fd_out = open(cmd->stdout_redirect, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out == -1)
		{
			perror("outfile open");
			exit(EXIT_FAILURE);
		}
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		i = 0;
		while (cmd->args[i])
			i++;
		cmd->args[i - 1] = NULL; //free if dynamically allocated
	}
	if (ft_strncmp(cmd->stdin_redirect, "/dev/stdin", 11))
	{
		fd_in = open(cmd->stdin_redirect, O_RDONLY);
		if (fd_in == -1)
		{
			perror("infile open");
			exit(EXIT_FAILURE);
		}
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
}

int	exec_cmd(t_command *cmd_list, char **cmd_wargs, char **env)
{
	char	*path;
	bool	path_allocated;

	setup_redirection(cmd_list);
	if (ft_isbuiltin(cmd_wargs))
		exit(EXIT_SUCCESS);
	if (ft_strchr(cmd_wargs[0], '/'))
		path = cmd_wargs[0];
	else
	{
		path = get_path(cmd_wargs[0], env);
		path_allocated = true;
	}
	if (path == NULL) // redundant?
	{
		ft_free_array((void **)cmd_wargs);
		perror("Cmd not found");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd_wargs, env) == -1)
	{
		if (path_allocated)
			free(path);
		ft_free_array((void **)cmd_wargs);
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

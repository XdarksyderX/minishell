/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:28:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 18:27:09 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_pipes(t_command *cmd_list, char **cmd_wargs, char **env)
{
	int	pid;
	int	fd[2];
	int	in_fd;

	in_fd = STDIN_FILENO;
	while (cmd_list)
	{
		if (cmd_list->next && pipe(fd) < 0)
			exit_handler(EXIT_FAILURE, cmd_list, "pipe");
		pid = fork();
		if (pid == 0)
		{
			if (in_fd != STDIN_FILENO)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (cmd_list->next)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			setup_redirection(cmd_list);
			exec_cmd(cmd_list, cmd_wargs, env);
		}
		else
		{
			wait(NULL);
			if (cmd_list->next)
				close(fd[1]);
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			if (cmd_list->next)
				in_fd = fd[0];
		}
		cmd_list = cmd_list->next;
	}
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	exit_handler(EXIT_SUCCESS, cmd_list, NULL);
}

void	execute(t_command *cmd_list, char **cmd_wargs, char **env)
{
	if (!cmd_list->next)
	{
		setup_redirection(cmd_list);
		exec_cmd(cmd_list, cmd_wargs, env);
	}
	else
		handle_pipes(cmd_list, cmd_wargs, env);
}

void	exec_cmd(t_command *cmd_list, char **cmd_wargs, char **env)
{
	char	*path;
	bool	path_allocated;

	ft_isbuiltin(cmd_wargs, cmd_list);
	if (ft_strchr(cmd_wargs[0], '/'))
		path = cmd_wargs[0];
	else
	{
		path = get_path(cmd_wargs[0], env);
		path_allocated = true;
	}
	if (path == NULL)
		exit_handler(EXIT_FAILURE, cmd_list, "Cmd not found");
	if (execve(path, cmd_wargs, env) == -1)
	{
		if (path_allocated)
			free(path);
		exit_handler(EXIT_FAILURE, cmd_list, "Execve error");
	}
}

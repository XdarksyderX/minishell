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

void	child_process(t_shell *shell, int fd[2], int in_fd, char **env)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (shell->top_command->next)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	setup_redirection(shell);
	exec_cmd(shell, shell->top_command->args, env);
}

void	handle_pipes(t_shell *shell, char **env)
{
	int	pid;
	int	fd[2];
	int	in_fd;

	in_fd = STDIN_FILENO;
	while (shell->top_command)
	{
		if (shell->top_command->next && pipe(fd) < 0)
			exit_handler(EXIT_FAILURE, shell, "pipe");
		pid = fork();
		if (pid == 0)
			child_process(shell, fd, in_fd, env);
		else // make parent_process function
		{
			wait(NULL);
			if (shell->top_command->next)
				close(fd[1]);
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			if (shell->top_command->next)
				in_fd = fd[0];
		}
		shell->top_command = shell->top_command->next;
	}
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	exit_handler(EXIT_SUCCESS, shell, NULL);
}

void	execute(t_shell *shell, char **cmd_wargs, char **env)
{
	if (!shell->top_command->next)
	{
		setup_redirection(shell);
		exec_cmd(shell, cmd_wargs, env);
	}
	else
		handle_pipes(shell, env);
}

void	exec_cmd(t_shell *shell, char **cmd_wargs, char **env)
{
	char	*path;
	bool	path_allocated;

	ft_isbuiltin(cmd_wargs, shell);
	if (ft_strchr(cmd_wargs[0], '/'))
		path = cmd_wargs[0];
	else
	{
		path = get_path(cmd_wargs[0], env);
		path_allocated = true;
	}
	if (path == NULL)
		exit_handler(EXIT_FAILURE, shell, "Cmd not found");
	if (execve(path, cmd_wargs, env) == -1)
	{
		if (path_allocated)
			free(path);
		exit_handler(EXIT_FAILURE, shell, "Execve error");
	}
}

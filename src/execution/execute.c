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

void	execute(t_shell *shell, char **cmd_wargs, char **env)
{
	if (!shell->top_command->next)
	{
		setup_redirection(shell, true);
		exec_cmd(shell, cmd_wargs, env);
	}
	else
		handle_pipes(shell, env);
}

void	exec_cmd(t_shell *shell, char **cmd_wargs, char **env)
{
	char	*path;
	bool	path_allocated;

	execute_output_builtins(cmd_wargs, shell);
	if (ft_strchr(cmd_wargs[0], '/'))
		path = cmd_wargs[0];
	else
	{
		path = get_path(cmd_wargs[0], env);
		if (path == NULL)
		{
			errno = ENOENT;
			exit_handler(CMD_NOT_FOUND, shell, "Cmd not found");
		}
		path_allocated = true;
	}
	if (execve(path, cmd_wargs, env) == -1)
	{
		if (path_allocated)
			free(path);
		exit_handler(EXIT_FAILURE, shell, "Execve error");
	}
}

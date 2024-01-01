/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 21:17:36 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	ft_is_cd_or_exit(char **cmd_wargs, t_shell *shell)
{
	if (!ft_strncmp(cmd_wargs[0], "cd", 5))
	{
		shell->last_exit_status = ft_cd(shell, cmd_wargs);
		return (true);
	}
	if (!ft_strncmp(cmd_wargs[0], "exit", 5))
	{
		ft_exit(cmd_wargs, shell);
		return (true);
	}
	return (false);
}

void	ft_isbuiltin(char **cmd_wargs, t_shell *shell)
{
	if (!ft_strncmp(cmd_wargs[0], "echo", 5))
		ft_echo(cmd_wargs, shell);
	if (!ft_strncmp(cmd_wargs[0], "pwd", 4))
		ft_pwd(shell);
	if (!ft_strncmp(cmd_wargs[0], "env", 4))
		ft_env(shell->env, shell);
	//if (!ft_strncmp(cmd_wargs[0], "unset", 6))
	//	ft_env(cmd_wargs, shell);
	//if (!ft_strncmp(cmd_wargs[0], "export", 7))
	//	ft_setenv(cmd_wargs, shell);
}

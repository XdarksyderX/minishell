/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 14:08:27 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	ft_is_cd_or_exit(char **cmd_wargs, t_command *cmd_list)
{
	if (!ft_strncmp(cmd_wargs[0], "cd", 5))
	{
		ft_cd(cmd_wargs);
		return (true);
	}
	if (!ft_strncmp(cmd_wargs[0], "exit", 5))
	{
		ft_exit(cmd_wargs, cmd_list);
		return (true);
	}
	return (false);
}

void	ft_isbuiltin(char **cmd_wargs, t_command *cmd_list)
{
	if (!ft_strncmp(cmd_wargs[0], "echo", 5))
		ft_echo(cmd_wargs, cmd_list);
	if (!ft_strncmp(cmd_wargs[0], "pwd", 4))
		ft_pwd(cmd_list);
	if (!ft_strncmp(cmd_wargs[0], "env", 4))
		ft_env(cmd_wargs, cmd_list);
	/*if (!ft_strncmp(cmd_wargs[0], "unset", 6))
		ft_env(cmd_wargs, cmd_list);
	if (!ft_strncmp(cmd_wargs[0], "export", 7))
		ft_env(cmd_wargs, cmd_list);*/
}

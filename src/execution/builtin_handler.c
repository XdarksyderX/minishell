/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 17:21:41 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	ft_is_cd_or_exit(char **cmd_wargs)
{
	if (!ft_strncmp(cmd_wargs[0], "cd", 5))
	{
		ft_cd(cmd_wargs);
		return (true);
	}
	if (!ft_strncmp(cmd_wargs[0], "exit", 5))
	{
		ft_exit(cmd_wargs);
		return (true);
	}
	return (false);
}

bool	ft_isbuiltin(char **cmd_wargs)
{
	if (!ft_strncmp(cmd_wargs[0], "echo", 5))
	{
		ft_echo(cmd_wargs);
		return (true);
	}
	if (!ft_strncmp(cmd_wargs[0], "pwd", 4))
	{
		ft_pwd();
		return (true);
	}
	/*if (ft_strncmp(cmd_wargs[0], "env", 5))
	{
		ft_env(cmd_wargs);
		return (true);
	}*/
	return (false);
}

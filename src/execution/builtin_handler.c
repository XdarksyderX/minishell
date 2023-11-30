/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:23 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/30 15:07:49 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	ft_isbuiltin(char *cmd)
{
	char	**cmd_wflags;

	cmd_wflags = ft_split(cmd, ' ');
	if (!ft_strncmp(cmd_wflags[0], "echo", 5))
	{
		ft_echo(cmd_wflags);
		return (true);
	}
	if (!ft_strncmp(cmd_wflags[0], "exit", 5))
	{
		ft_exit(cmd_wflags);
		return (true);
	}
	if (!ft_strncmp(cmd_wflags[0], "pwd", 4))
	{
		ft_pwd();
		return (true);
	}
	/*if (ft_strncmp(cmd_wflags[0], "env", 5))
	{
		ft_env(cmd_wflags);
		return (true);
	}*/
	if (!ft_strncmp(cmd_wflags[0], "cd", 5))
	{
		ft_cd(cmd_wflags);
		return (true);
	}
	return (false);
}

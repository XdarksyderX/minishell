/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:17:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/22 22:32:50 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

void	ft_env(char **envp, t_shell *shell)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	exit_handler(EXIT_SUCCESS, shell, NULL);
}

int	ft_unset(char **cmd, t_shell *shell)
{
	int	i;

	i = 0;
	while (cmd[++i])
		ft_unsetenv(cmd[i], shell->env);
	return (0);
}

int	ft_export(char **cmd, t_shell *shell)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (ft_setenv(cmd[i], &shell->env) == -1)
			return (-1);
	}
	return (0);
}

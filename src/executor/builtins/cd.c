/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:00 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/01 11:53:57 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	cd_to_home(t_shell *shell)
{
	char	*path_to_home;

	path_to_home = ft_getenv("HOME", shell->env);
	if (!path_to_home)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(path_to_home) == -1)
	{
		perror("cd");
		free(path_to_home);
		return (EXIT_FAILURE);
	}
	else
	{
		free(path_to_home);
		return (EXIT_SUCCESS);
	}
}

int	ft_cd(t_shell *shell, char **cmd)
{
	if (!cmd[1])
		return (cd_to_home(shell));
	if (chdir(cmd[1]) == -1)
	{
		perror("cd");
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

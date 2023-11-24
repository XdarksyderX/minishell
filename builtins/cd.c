/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:00 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/24 14:02:54 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	cd_to_home(char **cmd)
{
	char	*path_to_home;

	path_to_home = getenv("HOME");
	if (!path_to_home)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(path_to_home) == -1)
	{
		perror("cd");
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

int	ft_cd(char **cmd)
{
	if (ft_strncmp(cmd[0], "cd", 3) != 0)
		return (bad_argument()); //to implement
	if (!cmd[1])
		return (cd_to_home(cmd));
	if (chdir(cmd[1]) == -1)
	{
		perror("cd");
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

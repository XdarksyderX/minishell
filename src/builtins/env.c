/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:17:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/24 14:34:17 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(char	**cmd, char **env)
{
	int	i;

	if (ft_strncmp(cmd[0], "env", 4) != 0)
		return (bad_argument()); //to implement
	if (cmd[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (env[i])
		ft_putendl_fd(env[i], 1);
	return (EXIT_SUCCESS);
}

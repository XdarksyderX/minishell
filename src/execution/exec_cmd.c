/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:28:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/29 16:28:31 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_path(char *cmd, char **env)
{
	char	**possible_paths;
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	possible_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (possible_paths[++i])
	{
		temp = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_free_array((void **)possible_paths);
	return (path);
}

int	exec_cmd(char *str_cmd, char **env)
{
	char	**cmd_wflags;
	char	*path;

	cmd_wflags = ft_split(str_cmd, ' ');
	if (cmd_wflags == NULL)
	{
		perror("Cmd error");
		return (EXIT_FAILURE);
	}
	path = get_path(cmd_wflags[0], env);
	if (path == NULL)
	{
		ft_free_array((void **)cmd_wflags);
		perror("Cmd not found");
		return (EXIT_FAILURE);
	}
	if (execve(path, cmd_wflags, env) == -1)
	{
		free(path);
		ft_free_array((void **)cmd_wflags);
		perror("Execve error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

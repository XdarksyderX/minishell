/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:49:12 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 14:52:34 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	ft_free_str_array((void **)possible_paths);
	return (path);
}

void	ft_free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free (array);
}

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

int	ft_getenv_index(char *env, char **envp)
{
	int		i;
	size_t	name_len;

	i = 0;
	name_len = ft_strlen(env);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], env, name_len) == 0 && envp[i][name_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_getenv(char *env, char **envp)
{
	int		i;
	char	*entry;
	char	*value;
	size_t	name_len;

	i = 0;
	name_len = ft_strlen(env);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], env, name_len) == 0 && envp[i][name_len] == '=')
		{
			entry = envp[i] + name_len + 1;
			value = strdup(entry);
			return (value);
		}
		i++;
	}
	return (NULL);
}

int	ft_unsetenv(char *env, char **envp)
{
	int	i;

	if (!env)
		return (0);
	i = ft_getenv_index(env, envp);
	if (i != -1)
	{
		free(envp[i]);
		while (envp[i + 1])
		{
			envp[i] = envp[i + 1];
			i++;
		}
		envp[i] = NULL;
	}
	return (0);
}

static char	**realloc_envp(char **envp, int size)
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (size + 1));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (envp[++i] && i < size)
	{
		new_envp[i] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	new_envp[i] = NULL;
	free(envp);
	return (new_envp);
}

int	ft_setenv(char *env, char ***envp)
{
	int		i;

	i = 0;
	while ((*envp)[i])
	{
		if (ft_strncmp((*envp)[i], env, ft_strlen(env)) == 0)
		{
			free((*envp)[i]);
			(*envp)[i] = ft_strdup(env);
			return (0);
		}
		i++;
	}
	*envp = realloc_envp(*envp, i + 1);
	if (!(*envp))
		return (-1);
	(*envp)[i] = ft_strdup(env);
	return (0);
}

void	ft_env(char **envp, t_command *cmd_list)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	exit_handler(EXIT_SUCCESS, cmd_list, NULL);
}

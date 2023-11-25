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

#include "../../inc/builtins.h"

extern t_shell	g_shell;

int	ft_getenv(char *env)
{
	int	i;

	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], env, ft_strlen(env)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_unsetenv(char *env)
{
	int	i;

	if (env == NULL)
		return (0);
	i = ft_get_env(env);
	if (i != -1)
	{
		free(g_shell.env[i]);
		g_shell.env[i] = NULL;
		while (g_shell.env[i + 1])
		{
			g_shell.env[i] = g_shell.env[i + 1];
			i++;
		}
	}
	return (0);
}

int	ft_setenv(char *env)
{
	int		i;
	char	*tmp;
	char	**new_envp;

	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], env, ft_strlen(env)) == 0)
		{
			tmp = g_shell.env[i];
			g_shell.env[i] = ft_strdup(env);
			free(tmp);
			exit(0);
		}
		i++;
	}
	new_envp = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (g_shell.env[++i])
		new_envp[i] = ft_strdup(g_shell.env[i]);
	new_envp[i] = ft_strdup(env);
	new_envp[i + 1] = NULL;
	free(g_shell.env);
	g_shell.env = new_envp;
}

int	ft_env(void)
{
	int	i;

	i = 0;
	while (g_shell.env[i])
	{
		printf("%s\n", g_shell.env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

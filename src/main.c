/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 20:41:03 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	shell->env = (char **)malloc((i + 1) * sizeof(char *));
	i = -1;
	while (env[++i])
		shell->env[i] = ft_strdup(env[i]);
	shell->env[i] = NULL;
	shell->last_exit_status = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		exit(127);
	}
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (EXIT_FAILURE);
	init_shell(shell, env);
	(void)argv;
	start_minishell(shell);
	return (EXIT_SUCCESS);
}

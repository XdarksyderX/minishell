/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/29 16:27:48 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	start_minishell(t_command *cmd_list, char **env)
{
	char	*input;
	int		pid;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			continue ;
		if (input[0])
			add_history(input);
		if (ft_strncmp(input, "exit", 5) == 0)
			exit(0);
		cmd_list = ft_get_command_list(input);
		//debug_print_cmd_list(cmd_list);
		pid = fork();
		if (pid == 0)
		{
			exec_cmd(input, env);
			exit(0);
		}
		wait(NULL);
		free(input);
	}
}

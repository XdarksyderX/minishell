/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/08 17:58:37 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*command_line(char *input, t_shell *shell)
{
	input = readline("minishell> ");
	if (!input)
	{
		ft_free_array((void **)shell->env);
		free(shell);
		exit(0);
	}
	if (input[0])
	{
		add_history(input);
		return (input);
	}
	else
		return (NULL);
}

void	start_minishell(t_shell *shell)
{
	char	*input;
	int		pid;
	int		status;

	ft_sighandler();
	input = NULL;
	while (1)
	{
		g_interactive_mode = 1;
		input = command_line(input, shell);
		if (!input)
			continue ;
		g_interactive_mode = 0;
		input = ft_expand(input, shell);
		shell->top_command = ft_create_command_list(input);
		if (is_state_changing_builtin(shell->top_command->args, shell))
			continue ;
		pid = fork();
		if (pid == 0)
			execute(shell, shell->top_command->args, shell->env);
		waitpid(pid, &status, 0);
		shell->last_exit_status = WEXITSTATUS(status);
		shell->top_command = ft_free_cmd_list(shell->top_command);
	}
}

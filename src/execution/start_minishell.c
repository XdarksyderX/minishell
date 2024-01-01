/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 20:33:39 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	g_interactive_mode;

static char	*command_line(char *input)
{
	input = readline("minishell> ");
	if (!input)
		exit(0);
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
		input = command_line(input);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/22 22:16:30 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	g_interactive_mode;

void	ft_ctrl_c(int signal)
{
	if (g_interactive_mode)
	{
		(void)signal;
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		printf("\033[K\n");
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
	else
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
	}
}

// ctrl D sends signal EOF which is handled in start_minishell loop
void	ft_sighandler(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
}

void	start_minishell(t_command *cmd_list, char **env)
{
	char	*input;
	int		pid;

	ft_sighandler();
	while (1)
	{
		g_interactive_mode = 1;
		input = readline("minishell> ");
		if (!input)
			exit(0);
		if (input[0])
			add_history(input);
		else
			continue ;
		input = ft_expand(input, env);
		cmd_list = ft_create_command_list(input);
		g_interactive_mode = 0;
		if (ft_is_cd_or_exit(cmd_list->args, cmd_list))
			continue ;
		//debug_print_cmd_list(cmd_list);
		//continue;
		pid = fork();
		if (pid == 0)
			execute(cmd_list, cmd_list->args, env);
		wait(NULL);
		ft_free_cmd_list(cmd_list);
		cmd_list = NULL;
	}
}

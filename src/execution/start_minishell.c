/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/11 15:17:03 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_ctrl_c(int signal)
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
		input = readline("minishell> ");
		if (!input)
			continue ;
		if (input[0])
			add_history(input);
		else
			continue ;
		cmd_list = ft_get_command_list(input);
		if (ft_isbuiltin(input))
			continue ;
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
	(void) cmd_list;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 17:23:06 by vnaslund         ###   ########.fr       */
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
		cmd_list = ft_create_command_list(input);
		free(input);
		if (ft_is_cd_or_exit(cmd_list->args))
			continue ;
		//debug_print_cmd_list(cmd_list);
		pid = fork();
		if (pid == 0)
		{
			exec_cmd(cmd_list->args, env);
			exit(0);
		}
		wait(NULL);
	}
}

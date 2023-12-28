/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:56:31 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/25 16:56:58 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int g_interactive_mode;

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

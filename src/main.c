/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/27 13:15:25 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_shell	g_shell;

int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void)argv, (void)env;
	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		exit(127);
	}
	while (1)
	{
		input = readline("minishell> ");
		add_history(input);
		ft_get_command_list(input);
		free(input);
	}
	return (0);
}

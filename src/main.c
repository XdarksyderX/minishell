/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/27 14:17:22 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_command	*cmd_list;
	char		*input;

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
		cmd_list = ft_get_command_list(input);
		debug_print_cmd_list(cmd_list);
		free(input);
	}
	return (0);
}

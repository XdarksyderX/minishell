/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/29 13:34:58 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	start_minishell(t_command *cmd_list, char **env)
{
	char	*input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			continue ;
		if (input[0])
			add_history(input);
		cmd_list = ft_get_command_list(input);
		//debug_print_cmd_list(cmd_list);
		if (ft_strncmp(input, "clear", 6) == 0)
		{
			int pid = fork();
			char *args[] = {"/usr/bin/clear", NULL};
			if (pid == 0)
				execve("/usr/bin/clear", args, env);
			wait(NULL);
		}
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	*cmd_list;

	cmd_list = NULL;
	(void)argv;
	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		exit(127);
	}
	start_minishell(cmd_list, env);
	return (EXIT_SUCCESS);
}

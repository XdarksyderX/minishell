/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 14:40:53 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

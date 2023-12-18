/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:32:55 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 17:52:51 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_command	*ft_create_command_list(char *input)
{
	t_command	*cmd_list;
	char		**commands;
	int			i;

	i = 0;
	commands = ft_split(input, '|');
	while (commands[i])
	{
		cmd_list = ft_add_command(cmd_list, commands[i]);
		i++;
	}
	fill_default_redirections(cmd_list);
	return (cmd_list);
}

t_command	*ft_add_command(t_command *cmd_list, char *command)
{
	t_command	*new_cmd;
	t_command	*current;

	new_cmd = ft_create_command(command);
	if (cmd_list == NULL)
		return (new_cmd);
	current = cmd_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_cmd;
	return (cmd_list);
}

t_command	*ft_create_command(char *command)
{
	t_command	*new_cmd;
	char		**tokens;
	int			i;
	int			arg_count;

	new_cmd = malloc(sizeof(t_command));
	if (!new_cmd)
		return (NULL);
	tokens = ft_split(command, ' ');
	i = -1;
	arg_count = 0;
	while (tokens[++i])
	{
		handle_redirection(new_cmd, tokens, &i);
		if (tokens[i])
			arg_count++;
		else
			break ; // added for segfault fix
	}
	new_cmd->args = create_args_array(tokens, arg_count);
	new_cmd->next = NULL;
	free(tokens); // Probably ft_free_array tokens
	return (new_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:32:49 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 12:41:28 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	handle_redirection(t_command *cmd, char **tokens, int *i)
{
	if (ft_strncmp(tokens[*i], ">", 1) == 0)
	{
		if (tokens[*i][1] == '>')
		{
			if (ft_strlen(tokens[*i]) == 2)
				cmd->stdout_redirect = ft_strdup(tokens[++(*i)]);
			else
				cmd->stdout_redirect = ft_strdup(tokens[(*i)] + 2);
			cmd->append = true;
		}
		else
		{
			if (ft_strlen(tokens[*i]) == 1)
				cmd->stdout_redirect = ft_strdup(tokens[++(*i)]);
			else
				cmd->stdout_redirect = ft_strdup(tokens[(*i)] + 1);
		}
	}
	else if (ft_strncmp(tokens[*i], "<", 1) == 0)
		cmd->stdin_redirect = ft_strdup(tokens[++(*i)]);
}

char	**create_args_array(char **tokens, int arg_count)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	i = -1;
	j = 0;
	while (tokens[++i])
	{
		if (tokens[i][0] == '>' || tokens[i][0] == '<')
			break ;
		else
			args[j++] = ft_strdup(tokens[i]);
	}
	args[j] = NULL;
	return (args);
}

void	fill_default_redirections(t_command *cmd_list)
{
	t_command	*current_cmd;

	current_cmd = cmd_list;
	while (current_cmd != NULL)
	{
		if (current_cmd->stdin_redirect == NULL)
			current_cmd->stdin_redirect = ft_strdup("/dev/stdin");
		if (current_cmd->stdout_redirect == NULL)
			current_cmd->stdout_redirect = ft_strdup("/dev/stdout");
		current_cmd = current_cmd->next;
	}
}

#include "../../inc/parser.h"

void	handle_redirection(t_command *cmd, char **tokens, int *i)
{
	if (ft_strncmp(tokens[*i], ">", 1) == 0)
		cmd->stdout_redirect = ft_strdup(tokens[++(*i)]);
	else if (ft_strncmp(tokens[*i], "<", 1) == 0)
		cmd->stdin_redirect = ft_strdup(tokens[++(*i)]);
	else if (ft_strncmp(tokens[*i], "2>", 1) == 0)
		cmd->stderr_redirect = ft_strdup(tokens[++(*i)]);
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
		if (ft_strncmp(tokens[i], ">", 1)
			!= 0 && ft_strncmp(tokens[i], "<", 1) != 0
			&& strcmp(tokens[i], "2>") != 0)
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
		if (current_cmd->stderr_redirect == NULL)
			current_cmd->stderr_redirect = ft_strdup("/dev/stderr");
		current_cmd = current_cmd->next;
	}
}

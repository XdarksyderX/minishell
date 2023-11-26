#include "../../inc/parser.h"

static int	count_args_before_redirection(char *line)
{
	int	i;
	int	arg_count;
	int	start;

	i = 0;
	arg_count = 0;
	start = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\0'
			|| line[i] == '<' || line[i] == '>')
		{
			if (i > start)
				arg_count++;
			if (line[i] == '<' || line[i] == '>')
				break ;
			start = i + 1;
		}
		i++;
	}
	return (arg_count);
}

static void	extract_args(char *line, char **args)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (line[i] && line[i] != '<' && line[i] != '>')
	{
		if (line[i] == ' ' || line[i] == '\0')
		{
			if (i > start)
				args[j++] = strndup(line + start, i - start);
			start = i + 1;
		}
		i++;
	}
	if (i > start)
		args[j++] = strndup(line + start, i - start);
	args[j] = NULL;
}

char	**extract_command_and_args(char *line)
{
	char	**args;
	int		arg_count;

	arg_count = count_args_before_redirection(line);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	extract_args(line, args);
	return (args);
}

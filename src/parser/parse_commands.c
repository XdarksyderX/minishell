#include "../../inc/parser.h"

t_command	*ft_new_command(char *line)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	new->args = extract_command_and_args(line);
	new->next = NULL;
	return (new);
}

t_command	*ft_get_command_list(char *line)
{
	t_command	*new;
	char		**commands;

	commands = ft_split_commands(line);
	while (*commands)
	{
		new = ft_new_command(*commands);
		new->next = ft_get_command_list(*commands);
		commands++;
	}
	return (new);
}

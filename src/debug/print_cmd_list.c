#include "inc/minishell.h"

void	debug_print_command(t_command *cmd)
{
	int	i = 0;

	if (cmd)
	{
		printf("Command Details:\n");
		printf("  Args");
		while (cmd->args[i])
			printf(": %s\n", cmd->args[i++]);
		printf("  Path: %s\n", cmd->path);
		printf("  Infile: %s\n", cmd->infile);
		printf("  Outfile: %s\n", cmd->outfile);
		printf("  Errfile: %s\n", cmd->errfile);
		printf("\n");
	}
}

void	debug_print_cmd_list(t_command *cmd_list)
{
	t_command	*current = cmd_list;

	printf("Command List:\n");
	while (current != NULL)
	{
		debug_print_command(current);
		current = current->next;
	}
}

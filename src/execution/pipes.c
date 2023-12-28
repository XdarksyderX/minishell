#include "../../inc/minishell.h"

static void	parent_process(t_shell *shell, int *in_fd, int fd[2])
{
	wait(NULL);
	if (shell->top_command->next)
	{
		close(fd[1]);
		if (*in_fd != STDIN_FILENO)
			close(*in_fd);
		*in_fd = fd[0];
	}
	else if (*in_fd != STDIN_FILENO)
		close(*in_fd);
}

static void	child_process(t_shell *shell, int fd[2], int in_fd, char **env)
{
	if (in_fd != STDIN_FILENO)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (shell->top_command->next)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	setup_redirection(shell);
	exec_cmd(shell, shell->top_command->args, env);
}

void	handle_pipes(t_shell *shell, char **env)
{
	int	pid;
	int	fd[2];
	int	in_fd;

	in_fd = STDIN_FILENO;
	while (shell->top_command)
	{
		if (shell->top_command->next && pipe(fd) < 0)
			exit_handler(EXIT_FAILURE, shell, "pipe");
		pid = fork();
		if (pid == 0)
			child_process(shell, fd, in_fd, env);
		else
			parent_process(shell, &in_fd, fd);
		shell->top_command = shell->top_command->next;
	}
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	exit_handler(EXIT_SUCCESS, shell, NULL);
}

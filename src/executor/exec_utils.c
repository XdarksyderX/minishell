/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:06:01 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 18:11:19 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*test_paths(char **possible_paths, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (possible_paths[++i])
	{
		temp = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	return (path);
}

char	*get_path(char *cmd, char **env)
{
	char	**possible_paths;
	int		i;
	char	*path;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	if (!env[i])
		return (NULL);
	possible_paths = ft_split(env[i] + 5, ':');
	path = test_paths(possible_paths, cmd);
	ft_free_array((void **)possible_paths);
	return (path);
}

void	execute_heredoc(char *delimiter, int heredoc_fd[2])
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1))
			break ;
		write(heredoc_fd[1], line, ft_strlen(line));
		write(heredoc_fd[1], "\n", 1);
		free(line);
	}
	close(heredoc_fd[1]);
	dup2(heredoc_fd[0], STDIN_FILENO);
	close(heredoc_fd[0]);
}

void	redirect_stdin(t_shell *shell, bool handle_heredoc)
{
	int	heredoc_fd[2];
	int	fd_in;

	if (ft_strncmp(shell->top_command->stdin_redirect, "/dev/stdin", 11))
	{
		fd_in = open(shell->top_command->stdin_redirect, O_RDONLY);
		if (fd_in == -1)
			exit_handler(EXIT_FAILURE, shell, "infile open");
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (shell->top_command->heredoc && handle_heredoc)
	{
		if (pipe(heredoc_fd) < 0)
			exit_handler(1, shell, "pipe");
		execute_heredoc(shell->top_command->delimiter, heredoc_fd);
	}
}

void	setup_redirection(t_shell *shell, bool handle_heredoc)
{
	int	fd_out;

	if (ft_strncmp(shell->top_command->stdout_redirect, "/dev/stdout", 12))
	{
		if (shell->top_command->append)
			fd_out = open(shell->top_command->stdout_redirect,
					O_WRONLY | O_CREAT | O_APPEND, 0666);
		else
			fd_out = open(shell->top_command->stdout_redirect,
					O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out == -1)
			exit_handler(EXIT_FAILURE, shell, "outfile open");
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	redirect_stdin(shell, handle_heredoc);
}

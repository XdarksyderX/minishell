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

char	*get_path(char *cmd, char **env)
{
	char	**possible_paths;
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	possible_paths = ft_split(env[i] + 5, ':');
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
	ft_free_array((void **)possible_paths);
	return (path);
}

void	redirect_stdin(t_shell *shell)
{
	int	fd_in;

	if (ft_strncmp(shell->top_command->stdin_redirect, "/dev/stdin", 11))
	{
		fd_in = open(shell->top_command->stdin_redirect, O_RDONLY);
		if (fd_in == -1)
			exit_handler(EXIT_FAILURE, shell, "infile open");
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
}

void	setup_redirection(t_shell *shell)
{
	int	fd_out;
	int	i;

	if (ft_strncmp(shell->top_command->stdout_redirect, "/dev/stdout", 12))
	{
		fd_out = open(shell->top_command->stdout_redirect,
				O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out == -1)
			exit_handler(EXIT_FAILURE, shell, "outfile open");
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		i = 0;
		while (shell->top_command->args[i])
			i++;
		free(shell->top_command->args[i]);
		free(shell->top_command->args[i - 1]);
		shell->top_command->args[i - 1] = NULL;
	}
	redirect_stdin(shell);
}

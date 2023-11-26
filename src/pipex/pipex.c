/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:34:36 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/26 14:46:46 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pipex(char **argv, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (child_process(argv, env, fd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		if (parent_process(argv, env, fd) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	child_process(char **av, char **env, int fd[2])
{
	int	infile;

	close(fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Infile open error");
		return (EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("Child: Error duplicating STDIN");
		return (EXIT_FAILURE);
	}
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Child: Error duplicating STDOUT");
		return (EXIT_FAILURE);
	}
	close(fd[1]);
	if (exec_cmd(av[2], env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parent_process(char **av, char **env, int fd[2])
{
	int	outfile;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Parent: Error duplicating STDIN");
		exit(1);
	}
	close(fd[0]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Outfile open error");
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("Parent: Error duplicating STDOUT");
		exit(1);
	}
	close(outfile);
	if (exec_cmd(av[3], env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	exec_cmd(char *str_cmd, char **env)
{
	char	**cmd_wflags;
	char	*path;

	cmd_wflags = ft_split(str_cmd, ' ');
	if (cmd_wflags == NULL)
	{
		perror("Cmd error");
		return (EXIT_FAILURE);
	}
	path = get_path(cmd_wflags[0], env);
	if (path == NULL)
	{
		ft_freearray(cmd_wflags);
		perror("Cmd not found");
		return (EXIT_FAILURE);
	}
	if (execve(path, cmd_wflags, env) == -1)
	{
		free(path);
		ft_freearray(cmd_wflags);
		perror("Execve error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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
	ft_freearray((void **)possible_paths);
	return (path);
}
/*
          +------------------------+
          |                        |
          |      Child Process     |
          |                        |
          +------------------------+
          |     infile = STDIN     |  
          | write to STDOUT (fd[1])|------------------+
          +------------------------+                  |
                                                      |
                                                      V
          +------------------------+             +--------+ fd[1] = write
          |                        |             |  PIPE  |
          |    Parent Process      |             +--------+ fd[0] = read
          |                        |                  |
          +------------------------+                  |
          | read from STDIN (fd[0])|<-----------------+
          |write to STDOUT(outfile)|
          +------------------------+
*/
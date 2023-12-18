#ifndef EXECUTE_H
# define EXECUTE_H

# include "builtins.h"
# include "pipex.h"

void	start_minishell(t_command *cmd_list, char **env);
bool	ft_isbuiltin(char **cmd_wargs);

#endif
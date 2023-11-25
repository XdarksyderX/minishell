#ifndef SHELL_H
# define SHELL_H

typedef struct s_shell {
	char	**env;
	char	**path;
	int		last_exit_status;
}	t_shell;

#endif
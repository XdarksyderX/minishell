#ifndef SHELL_H
# define SHELL_H

typedef struct s_shell {
	char		**env;
	int			last_exit_status;
	t_command	*top_command;
}	t_shell;

typedef struct s_command {
	char		**args;
	char		*path;
	char		*infile;
	char		*outfile;
	char		*errfile;
	t_command	*next;
	t_command	*prev;
}	t_command;

#endif
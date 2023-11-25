#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# include "helpers.h"
# include "shell.h"

int		ft_echo(char *str, bool n_flag);
void	ft_exit(void);
int		ft_pwd(void);
int		ft_cd(char *dir);
int		ft_env(void);

#endif
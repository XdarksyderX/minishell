#ifndef EXPANDER_H
# define EXPANDER_H

# include "../libft/libft.h"
# include "shell.h"
# include <stdbool.h>

char	*ft_getenv(char *env, char **envp);
int		ft_unsetenv(char *env, char **envp);
int		ft_setenv(char *env, char ***envp);
char	*ft_expand(char *input, t_shell *shell);
int		is_valid_var_char(int c);
char	*ft_get_first_env_var(char *str);
char	*ft_replace(char *original, const char *insert,
			size_t start, size_t end);

#endif
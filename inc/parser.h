#ifndef PARSER_H
# define PARSER_H

# define DELIMITERS "|"

# include "shell.h"
# include "builtins.h"

char	**ft_split_commands(char *line);

#endif
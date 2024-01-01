#include "../../inc/expander.h"

static bool	is_in_single_quotes(char *str, size_t pos)
{
	bool	in_quotes;
	size_t	i;

	in_quotes = false;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'')
			in_quotes = !in_quotes;
		i++;
	}
	return (in_quotes);
}

static char	*get_expanded_var(char *input, t_shell *shell, size_t *i)
{
	char	*var_name;
	char	*var_value;
	size_t	var_start;
	size_t	var_end;

	var_name = ft_get_first_env_var(input + *i);
	if (!var_name)
		return (NULL);
	if (ft_strncmp(var_name, "?", 1) == 0)
		var_value = ft_itoa(shell->last_exit_status);
	else if (ft_strncmp(var_name, "$", 1) == 0)
		var_value = "$";
	else
		var_value = ft_getenv(var_name, shell->env);
	var_start = *i;
	var_end = var_start + ft_strlen(var_name) + 1;
	*i = var_start + ft_strlen(var_value);
	free(var_name);
	if (!var_value)
		return (ft_replace(input, "", var_start, var_end));
	if (ft_strncmp(var_name, "?", 1) == 0)
		free(var_value);
	return (ft_replace(input, ft_strdup(var_value), var_start, var_end));
}

static char	*expand_env_vars(char *expanded, t_shell *shell)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (expanded[i])
	{
		if (expanded[i] == '$' && !is_in_single_quotes(expanded, i))
		{
			temp = get_expanded_var(expanded, shell, &i);
			free(expanded);
			if (!temp)
				return (NULL);
			expanded = temp;
		}
		else
			i++;
	}
	return (expanded);
}

char	*ft_expand(char *input, t_shell *shell)
{
	return (expand_env_vars(input, shell));
}

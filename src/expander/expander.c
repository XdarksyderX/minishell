#include "../../inc/expander.h"

static bool is_in_single_quotes(char *str, size_t pos)
{
    bool in_quotes;
    size_t i;

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

static char *get_expanded_var(char *input, char **envp, size_t *i)
{
    char    *var_name;
    char    *var_value;
    size_t  var_start;
    size_t  var_end;

    var_name = ft_get_first_env_var(input + *i);
    if (!var_name)
        return (NULL);
    var_value = ft_getenv(var_name, envp);
    var_start = *i;
    var_end = var_start + ft_strlen(var_name) + 1;
    *i = var_start + (var_value ? ft_strlen(var_value) : 0);
    free(var_name);
    if (!var_value)
        return (ft_replace(input, "", var_start, var_end));
    return (ft_replace(input, var_value, var_start, var_end));
}


static char *expand_env_vars(char *input, char **envp)
{
    char    *expanded;
    char    *temp;
    size_t  i;

    expanded = ft_strdup(input);
    if (!expanded)
        return (NULL);
    i = 0;
    while (expanded[i])
    {
        if (expanded[i] == '$' && !is_in_single_quotes(expanded, i))
        {
            temp = get_expanded_var(expanded, envp, &i);
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

char    *ft_expand(char *input, char **envp)
{
    return (expand_env_vars(input, envp));
}

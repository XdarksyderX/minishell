#include "../../inc/expander.h"

int	is_valid_var_char(int c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

static bool	is_valid_var_start(char c)
{
	return (is_valid_var_char(c) || c == '$');
}

static char	*extract_env_var_name(char *start)
{
	char	*end;
	size_t	len;
	char	*var_name;

	end = start;
	while (*end && is_valid_var_char(*end))
		end++;
	len = end - start;
	var_name = (char *)malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_strlcpy(var_name, start, len + 1);
	return (var_name);
}

char	*ft_get_first_env_var(char *str)
{
	char	*var_name;

	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '$')
		{
			if (!is_valid_var_start(*(str + 1)))
				return (ft_strdup("$"));
			var_name = extract_env_var_name(str + 1);
			return (var_name);
		}
		str++;
	}
	return (NULL);
}

char	*ft_replace(char *original, const char *insert,
	size_t start, size_t end)
{
	char	*new_str;
	size_t	len_original;
	size_t	len_insert;
	size_t	new_len;

	if (!original || !insert)
		return (NULL);
	len_original = ft_strlen(original);
	len_insert = ft_strlen(insert);
	if (start > len_original || end > len_original || start > end)
	{
		free((void *)insert);
		return (ft_strdup(original));
	}
	new_len = start + len_insert + (len_original - end);
	new_str = (char *)malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, original, start + 1);
	ft_strlcpy(new_str + start, insert, len_insert + 1);
	free((void *)insert);
	ft_strlcpy(new_str + start + len_insert, original + end,
		len_original - end + 1);
	return (new_str);
}

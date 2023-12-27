#include "../../inc/expander.h"

int	is_valid_var_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*ft_get_first_env_var(char *str)
{
	size_t	len;
	char	*start;
	char	*end;
	char	*var_name;

	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '$' && is_valid_var_char(*(str + 1)))
		{
			start = str + 1;
			end = start;
			while (*(end) && is_valid_var_char(*(end)))
				end++;
			len = end - start + 1;
			var_name = (char *)malloc(len + 1);
			if (!var_name)
				return (NULL);
			ft_strlcpy(var_name, start, len);
			var_name[len] = '\0';
			return (var_name);
		}
		str++;
	}
	return (NULL);
}

char	*ft_replace(const char *original, const char *insert,
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
		return (ft_strdup(original));
	new_len = start + len_insert + (len_original - end);
	new_str = (char *)malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, original, start + 1);
	ft_strlcpy(new_str + start, insert, len_insert + 1);
	ft_strlcpy(new_str + start + len_insert, original + end,
		len_original - end + 1);
	return (new_str);
}

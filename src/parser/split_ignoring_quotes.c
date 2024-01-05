#include "../../inc/parser.h"

static size_t	skip_quoted(const char *s, char quote)
{
	size_t	len;

	len = 0;
	while (s[++len])
		if (s[len] == quote)
			return (len + 1);
	return (len);
}

static size_t	nbr_of_strs(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
		{
			s += skip_quoted(s, *s);
			ret++;
		}
		else if (*s != c)
		{
			while (*s && *s != c)
				s++;
			ret++;
		}
		else
			s++;
	}
	return (ret);
}

static char	*process_substring(const char **s, char c, bool is_quoted, bool del)
{
	size_t	len;
	char	*substring;

	len = 0;
	if (is_quoted)
	{
		len = skip_quoted(*s, **s);
		if (!del)
			substring = ft_substr(*s, 0, len);
		else
			substring = ft_substr(*s + 1, 0, len - 2);
		*s += len;
	}
	else
	{
		while ((*s)[len] && (*s)[len] != c)
			len++;
		substring = ft_substr(*s, 0, len);
		*s += len;
	}
	return (substring);
}

char	**split_ignoring_quotes(char const *s, char c, bool del_quotes)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (nbr_of_strs(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
			ret[i++] = process_substring(&s, c, true, del_quotes);
		else if (*s != c)
			ret[i++] = process_substring(&s, c, false, false);
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

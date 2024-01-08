/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ignoring_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:13 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/08 12:02:56 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static size_t	skip_quoted(const char *s, char quote)
{
	size_t	len;

	if (quote != '\"' && quote != '\'')
		return (1);
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

size_t	ft_len_without_quotes(const char *str)
{
	size_t	i;
	size_t	ret;

	if (!str)
		return (0);
	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			ret++;
		i++;
	}
	return (ret);
}

static char	*ft_delete_quotes(char *input)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = (char *)malloc(ft_len_without_quotes(input) + 1);
	if (!new)
	{
		free(input);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] != '\'' && input[i] != '\"')
		{
			new[j] = input[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	free(input);
	return (new);
}

char	**split_ignoring_quotes(char const *s, char c, bool del_quotes)
{
	char	**ret;
	size_t	len;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (nbr_of_strs(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		len = 0;
		if (*s != c)
		{
			while (s[len] && s[len] != c)
				len += skip_quoted(&s[len], s[len]);
			ret[i++] = ft_substr(s, 0, len);
			if (del_quotes)
				ret[i - 1] = ft_delete_quotes(ret[i - 1]);
			s += len;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

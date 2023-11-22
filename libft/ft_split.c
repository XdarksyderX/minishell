/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:23:22 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:29:34 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_destroy(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free (ret);
	return (NULL);
}

static size_t	nbr_of_strs(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
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

char	**ft_split(char const *s, char c)
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
				len++;
			ret[i++] = ft_substr(s, 0, len);
			if (!ret[i - 1])
				return (split_destroy(ret, i));
			s += len;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

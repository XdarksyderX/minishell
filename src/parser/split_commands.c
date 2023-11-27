/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:35:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/27 12:35:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static bool	is_delimiter(char c, const char *delimiters)
{
	int	i;

	i = 0;
	while (delimiters[i])
	{
		if (c == delimiters[i])
			return (true);
		i++;
	}
	return (false);
}

static bool	is_not_space_or_null(char c)
{
	return (c != ' ' && c != '\0');
}

int	ft_count_commands(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (is_delimiter(line[i], DELIMITERS)
			&& is_not_space_or_null(line[i + 1]))
		{
			count++;
			while (line[i] && (is_delimiter(line[i], DELIMITERS)
					|| line[i] == ' '))
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

static int	add_command(char **commands, char *line, int *i, int j)
{
	int	start;

	start = *i;
	while (line[*i] && (is_delimiter(line[*i], DELIMITERS) || line[*i] == ' '))
		(*i)++;
	commands[j++] = ft_substr(line, start, *i - start);
	return (j);
}

char	**ft_split_commands(char *line)
{
	char	**commands;
	int		i;
	int		j;

	commands = malloc(sizeof(char *) * (ft_count_commands(line) + 1));
	if (!commands)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (is_delimiter(line[i], DELIMITERS)
			&& is_not_space_or_null(line[i + 1]))
		{
			j = add_command(commands, line, &i, j);
			j = add_command(commands, line, &i, j);
		}
		else
			i++;
	}
	commands[j] = NULL;
	return (commands);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:21:06 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:44:17 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*list[10240] = {NULL};

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 10240 || read(fd, &line, 0) < 0)
	{
		destroy(&list[fd]);
		return (NULL);
	}
	if (init_list(&list[fd], fd) == -1)
		return (destroy(&list[fd]));
	if (!list[fd])
		return (destroy(&list[fd]));
	line = (char *)malloc(chars_in_next_line(list[fd]) + 1);
	if (!line)
		return (destroy(&list[fd]));
	fill_line(list[fd], line);
	if (!clean(&list[fd]))
	{
		free(line);
		return (destroy(&list[fd]));
	}
	return (line);
}

int	init_list(t_list **list, int fd)
{
	int		nbr_of_chars;
	char	*buffer;
	t_list	*new;

	while (!newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		nbr_of_chars = read(fd, buffer, BUFFER_SIZE);
		if (nbr_of_chars == 0)
		{
			free(buffer);
			return (1);
		}
		buffer[nbr_of_chars] = '\0';
		new = ft_lstnew_gnl(buffer);
		if (!new)
		{
			free(buffer);
			return (-1);
		}
		ft_lstadd_back(list, new);
	}
	return (1);
}

void	fill_line(t_list *list, char *line)
{
	int	i;
	int	s;

	if (list->str[0] == '\0')
	{
		line[0] = '\0';
		return ;
	}
	s = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				line[s] = '\n';
				line[s + 1] = '\0';
				return ;
			}
			line[s++] = list->str[i++];
		}
		list = list->next;
	}
	line[s] = '\0';
}

int	clean(t_list **list)
{
	t_list	*new;
	t_list	*last;
	char	*next_call;
	int		i;
	int		j;

	next_call = malloc(BUFFER_SIZE + 1);
	if (!next_call)
		return (0);
	last = *list;
	while (last->next)
		last = last->next;
	i = 0;
	while (last->str[i] != '\n' && last->str[i])
		i++;
	j = 0;
	while (last->str[i])
		next_call[j++] = last->str[++i];
	next_call[j] = '\0';
	new = ft_lstnew_gnl(next_call);
	if (!new)
		free(next_call);
	return (prepare(list, new, next_call));
}

int	prepare(t_list **list, t_list *new, char *buffer)
{
	t_list	*tmp;

	if (!new)
		return (0);
	if (!*list)
		return (1);
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new->str[0])
		*list = new;
	else
	{
		free(buffer);
		free(new);
	}
	return (1);
}

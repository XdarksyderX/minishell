/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:23:32 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/24 18:58:48 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
int		init_list(t_list **list, int fd);
void	fill_line(t_list *list, char *str);
int		chars_in_next_line(t_list *list);
int		newline(t_list *list);
t_list	*ft_lstnew_gnl(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		clean(t_list **list);
int		prepare(t_list **list, t_list *last, char *buffer);
char	*destroy(t_list **list);

#endif

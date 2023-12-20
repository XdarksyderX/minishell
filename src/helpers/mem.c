/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:35:31 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 15:02:15 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	ft_free_cmd_list(t_command *cmd_list)
{
	t_command	*temp;

	while (cmd_list)
	{
		ft_free_array((void **)cmd_list->args);
		free(cmd_list->stdin_redirect);
		free(cmd_list->stdout_redirect);
		temp = cmd_list->next;
		free(cmd_list);
		cmd_list = temp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:35:31 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/26 14:25:02 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_shell	g_shell;

void	ft_free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free (array);
	array = NULL;
}

void	ft_free_g_shell(void)
{
	ft_free_array((void **)g_shell.env);
	ft_free_array((void **)g_shell.path);
}

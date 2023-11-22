/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:37:03 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 18:51:00 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(char **cmd)
{
	char	cwd[128]; // random buffer size

	if (ft_strncmp(cmd[0], "pwd", 4) != 0)
		return (Bad_argument()); //to implement
	if (getcwd(cwd, 128))
	{
		ft_putendl_fd(cwd, 1);
		return (EXIT_SUCCESS);
	}
	else
	{
		perror("pwd error:");
		return (EXIT_FAILURE); // Revise return value
	}
}

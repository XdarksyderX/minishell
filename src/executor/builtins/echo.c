/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 14:20:11 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_echo(char **cmd, t_shell *shell)
{
	int		i;
	bool	print_nl;

	i = 1;
	print_nl = true;
	while (ft_strncmp(cmd[i++], "-n", 3) == 0)
		print_nl = false;
	i--;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i++], STDOUT_FILENO);
		if (cmd[i])
			write(1, " ", 1);
	}
	if (print_nl)
		write(STDOUT_FILENO, "\n", 1);
	exit_handler(EXIT_SUCCESS, shell, NULL);
}

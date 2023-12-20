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

#include "../../inc/minishell.h"

void	print_exit_status(char *str, char *start)
{
	while (str != start)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	// print exit status from t_shell, maybe expander takes care of this
	str += 2;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

void	ft_echo(char **cmd, t_command *cmd_list)
{
	char	*ptr;
	int		i;
	bool	print_nl;

	i = 1;
	print_nl = true;
	while (ft_strncmp(cmd[i++], "-n", 3) == 0)
		print_nl = false;
	i--;
	while (cmd[i])
	{
		ptr = ft_strnstr(cmd[i], "$?", ft_strlen(cmd[i]));
		if (ptr)
		{
			print_exit_status(cmd[i++], ptr); // maybe expander takes care of this
			if (cmd[i])
				write(1, " ", 1);
			continue ;
		}
		ft_putstr_fd(cmd[i++], STDOUT_FILENO);
		if (cmd[i])
			write(1, " ", 1);
	}
	if (print_nl)
		write(STDOUT_FILENO, "\n", 1);
	exit_handler(EXIT_SUCCESS, cmd_list, NULL);
}

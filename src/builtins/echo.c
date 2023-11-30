/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/30 14:52:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_echo(char **cmd)
{
	int		i;
	bool	print_nl;

	//if (ft_strncmp(cmd[0], "echo", 5) != 0)
	//	return (bad_argument()); //to implement
	if (!cmd[1])
	{
		write(1, "\n", 1);
		return (EXIT_SUCCESS);
	}
	i = 1;
	print_nl = true;
	while (ft_strncmp(cmd[i], "-n", 3) == 0)
	{
		print_nl = false;
		i++;
	}
	while (cmd[i])
		ft_putstr_fd(cmd[i++], 1); // add printing " " depending on how cmd argument is received
	if (print_nl)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}

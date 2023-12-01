/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/01 12:28:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_exit_status(char *str, char *start)
{
	while (str != start)
	{
		write(1, str, 1);
		str++;
	}
	// print exit status from t_shell
	str += 2;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_echo(char **cmd)
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
			print_exit_status(cmd[i++], ptr);
			if (cmd[i])
				write(1, " ", 1);
			continue ;
		}
		ft_putstr_fd(cmd[i++], 1);
		if (cmd[i])
			write(1, " ", 1);
	}
	if (print_nl)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}

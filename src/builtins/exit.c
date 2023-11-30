/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:22:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/30 15:03:28 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

long long	ft_atoi_longlong(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

static int	exit_syntax_error(char *str)
{
	long long	num;
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (1);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] != '\0')
		return (1);
	num = ft_atoi_longlong(str);
	if (num > LONG_MAX || num < LONG_MIN) // Comparison doesn't work for some reason !?!
		return (1); // LONG and LONG LONG have the same range so this code is redundant. I dont know another way to handle it like bash does.
	return (0);
}

void	exit_handler(int status)
{
	//free memory
	exit(status);
}

int	ft_exit(char **cmd)
{
	int	i;

	//if (ft_strncmp(cmd[0], "exit", 5) != 0)
	//	return (bad_argument()); //to implement
	ft_putendl_fd("exit", 1);
	i = 1;
	while (cmd[i])
		i++;
	if (i == 1)
		exit_handler(0); // to implement, 0 = exit status
	else if (exit_syntax_error(cmd[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit_handler(255); // to implement, 255 = exit status
	}
	else if (i != 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (EXIT_SUCCESS); // Weird behaviour but replicates bash, does not exit if 1 arg is numeric and there are too many args
	}
	else
		exit_handler(ft_atoi_longlong(cmd[1]) % 256);
	return (EXIT_SUCCESS);
}

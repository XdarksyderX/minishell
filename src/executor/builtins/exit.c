/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:22:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:39 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

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
	int	i;

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
	return (0);
}

void	exit_handler(int status, t_shell *shell, char *msg)
{
	ft_free_cmd_list(shell->top_command);
	ft_free_array((void **)shell->env);
	if (msg)
		perror(msg);
	free(shell);
	exit(status);
}

int	ft_exit(char **cmd, t_shell *shell)
{
	int	i;

	ft_putendl_fd("exit", 1);
	i = 1;
	while (cmd[i])
		i++;
	if (i == 1)
		exit_handler(0, shell, NULL);
	else if (exit_syntax_error(cmd[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit_handler(255, shell, NULL);
	}
	else if (i != 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (EXIT_SUCCESS);
	}
	else
		exit_handler(ft_atoi_longlong(cmd[1]) % 256, shell, NULL);
	return (EXIT_SUCCESS);
}

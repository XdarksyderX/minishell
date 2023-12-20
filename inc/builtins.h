/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:25 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 14:20:06 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# include "helpers.h"
# include "shell.h"

void	ft_echo(char **cmd, t_command *cmd_list);
int		ft_exit(char **cmd, t_command *cmd_list);
void	ft_pwd(t_command *cmd_list);
int		ft_cd(char **cmd);
int		ft_env(void);

#endif
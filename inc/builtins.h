/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:25 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/22 22:25:39 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "helpers.h"
# include "shell.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>

void	ft_echo(char **cmd, t_shell *shell);
int		ft_exit(char **cmd, t_shell *shell);
void	ft_pwd(t_shell *shell);
int		ft_cd(t_shell *shell, char **cmd);
void	ft_env(char **envp, t_shell *shell);
int		ft_unset(char **cmd, t_shell *shell);
int		ft_export(char **cmd, t_shell *shell);

#endif
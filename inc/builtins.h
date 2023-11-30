/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:25 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/30 14:57:38 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# include "helpers.h"
# include "shell.h"

int		ft_echo(char **cmd);
int		ft_exit(char **cmd);
int		ft_pwd(void);
int		ft_cd(char **cmd);
int		ft_env(void);

#endif
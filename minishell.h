/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:21:53 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/24 14:43:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

// builtins
int		ft_echo(char **cmd); // Single and multiple -n handled, "" and '' parsing not taken into account
int		ft_exit(char **cmd); // Copies bash functinality except when a number outside LONG range is entered
int		ft_pwd(char **cmd);
int		ft_cd(char **cmd); // Cd with and without arguments implmented (not cd '-')
int		ft_env(char	**cmd, char **env); // A lot of functionality to correctly pass the env variable still needed

// Path and ENV utils
char	*get_path(char *cmd, char **env); // first parameter is the command without flags

// Memory handling
void	ft_free_array(void **array);

#endif

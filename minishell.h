/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:21:53 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 16:55:07 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

// builtins
int		ft_echo(char **cmd); // Single and multiple -n handled, "" and '' parsing not taken into account

// Path and ENV utils
char	*get_path(char *cmd, char **env); // first parameter is the command without flags

// Memory handling
void	ft_free_array(void **array);

#endif

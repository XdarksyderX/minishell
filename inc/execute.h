/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:22:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 17:22:45 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "builtins.h"
# include "pipex.h"

void	start_minishell(t_command *cmd_list, char **env);
bool	ft_isbuiltin(char **cmd_wargs);
bool	ft_is_cd_or_exit(char **cmd_wargs);

#endif
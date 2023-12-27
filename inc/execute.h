/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:22:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 18:10:06 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "builtins.h"

void	start_minishell(t_command *cmd_list, char **env);
void	ft_isbuiltin(char **cmd_wargs, t_command *cmd_list);
bool	ft_is_cd_or_exit(char **cmd_wargs, t_command *cmd_list);

void	execute(t_command *cmd_list, char **cmd_wargs, char **env);
void	exec_cmd(t_command *cmd_list, char **cmd_wargs, char **env);
char	*get_path(char *cmd, char **env);
void	setup_redirection(t_command *cmd);
void	ft_free_array(void **array);

#endif
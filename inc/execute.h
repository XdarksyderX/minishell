/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:22:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 21:19:00 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "builtins.h"

void	start_minishell(t_shell *shell);
void	ft_isbuiltin(char **cmd_wargs, t_shell *shell);
bool	ft_is_cd_or_exit(char **cmd_wargs, t_shell *shell);

void	execute(t_shell *shell, char **cmd_wargs, char **env);
void	exec_cmd(t_shell *shell, char **cmd_wargs, char **env);
char	*get_path(char *cmd, char **env);
void	setup_redirection(t_shell *shell);
void	ft_free_array(void **array);

#endif
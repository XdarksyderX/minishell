/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:10:36 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 17:47:05 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "shell.h"

int		child_process(char **av, char **env, int fd[2]);
int		parent_process(char **av, char **env, int fd[2]);
int		exec_cmd(t_command *cmd_list, char **cmd_wargs, char **env);
char	*get_path(char *cmd, char **env);
void	ft_free_array(void **array);

#endif

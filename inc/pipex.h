/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:10:36 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/26 14:42:43 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

int		child_process(char **av, char **env, int fd[2]);
int		parent_process(char **av, char **env, int fd[2]);
int		exec_cmd(char *str_cmd, char **env);
char	*get_path(char *cmd, char **env);

#endif

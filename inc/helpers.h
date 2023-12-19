/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:39 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/19 17:41:11 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "minishell.h"

int		ft_setenv(char *env);
int		ft_getenv(char *env);
int		ft_unsetenv(char *env);
void	ft_free_cmd_list(t_command *cmd_list);
void	ft_free_array(void **array);

#endif
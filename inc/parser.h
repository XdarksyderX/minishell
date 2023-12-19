/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:38:04 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:37 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define DELIMITERS "|"

# include "shell.h"
# include "builtins.h"

t_command	*ft_create_command_list(char *input);
t_command	*ft_create_command(char *command);
t_command	*ft_add_command(t_command *cmd_list, char *command);
void		handle_redirection(t_command *cmd, char **tokens, int *i);
char		**create_args_array(char **tokens, int arg_count);
void		fill_default_redirections(t_command *cmd_list);
void		ft_free_array(void **array);

#endif
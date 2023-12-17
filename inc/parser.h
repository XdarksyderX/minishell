/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:38:04 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/15 23:38:26 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define DELIMITERS "|"

# include "shell.h"
# include "builtins.h"

char	**create_args_array(char **tokens, int arg_count);
void	fill_default_redirections(t_command *cmd_list);

#endif
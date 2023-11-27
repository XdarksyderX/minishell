/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:38:04 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/27 13:18:02 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define DELIMITERS "|"

# include "shell.h"
# include "builtins.h"

char		**ft_split_commands(char *line);
char		**extract_command_and_args(char *line);
t_command	*ft_get_command_list(char *line);

#endif
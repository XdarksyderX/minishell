/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/27 22:09:37 by xdarksyderx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "stdbool.h"

typedef struct s_command
{
	char				**args;
	char				*stdin_redirect;
	bool				heredoc;
	char				*delimiter;
	char				*stdout_redirect;
	bool				append;
	struct s_command	*next;
}	t_command;

typedef struct s_shell
{
	char		**env;
	int			last_exit_status;
	t_command	*top_command;
}	t_shell;

#endif
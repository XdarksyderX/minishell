/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 12:02:30 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef struct s_command
{
	char				*command;
	char				**args;
	char				*stdin_redirect;
	char				*stdout_redirect;
	char				*stderr_redirect;
	struct s_command	*next;
}	t_command;

typedef struct s_shell
{
	char		**env;
	int			last_exit_status;
	t_command	*top_command;
}	t_shell;

#endif
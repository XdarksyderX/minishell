/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/25 15:49:58 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef struct s_shell {
	char		**env;
	int			last_exit_status;
	t_command	*top_command;
}	t_shell;

typedef struct s_command {
	char		**args;
	char		*path;
	char		*infile;
	char		*outfile;
	char		*errfile;
	t_command	*next;
	t_command	*prev;
}	t_command;

#endif
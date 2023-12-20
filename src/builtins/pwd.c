/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:37:03 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/20 14:19:09 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

//Use getcwd with NULL and 0 to dynamically allocate
void	ft_pwd(t_command *cmd_list)
{
	char	*cwd;
	int		status;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
		status = EXIT_SUCCESS;
	}
	else
	{
		perror("Error");
		status = EXIT_FAILURE;
	}
	exit_handler(status, cmd_list, NULL);
}

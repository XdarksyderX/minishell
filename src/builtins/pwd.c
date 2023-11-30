/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:37:03 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/30 14:54:04 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

//Use getcwd with NULL and 0 to dynamically allocate
int	ft_pwd(void)
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
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:00 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/26 14:26:47 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

int	ft_cd(char *dir)
{
	if (dir == NULL || dir[0] == '\0')
	{
		if (chdir(getenv("HOME")) == -1)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
	}
	else if (chdir(dir) == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	ft_update_env(ft_strjoin("PWD=", getcwd(NULL, 0)));
	return (EXIT_SUCCESS);
}

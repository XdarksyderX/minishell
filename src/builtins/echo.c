/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/24 14:02:54 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

int	ft_echo(char *str, bool n_flag)
{
	if (str == NULL || str[0] == '\0')
	{
		if (!n_flag)
			printf("\n");
		return (0);
	}
	printf("%s", str);
	if (!n_flag)
		printf("\n");
	return (0);
}

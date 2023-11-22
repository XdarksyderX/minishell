/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:13 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 14:21:44 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minshell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
}

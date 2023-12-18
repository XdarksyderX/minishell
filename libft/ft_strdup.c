/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:38:30 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/18 12:29:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!(ret))
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

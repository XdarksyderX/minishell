/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:13:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/27 12:26:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (n > ft_strlen(s1))
		len = ft_strlen(s1);
	else
		len = n;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ret))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (s1[i] && i < n)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

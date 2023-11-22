/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:55 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:22:16 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		x = 0;
		while (haystack[i + x] == needle[x])
		{
			if ((x + i) >= len)
				return (NULL);
			else if (x == (ft_strlen(needle) - 1))
				return ((char *)haystack + i);
			x++;
		}
		i++;
	}
	return (NULL);
}

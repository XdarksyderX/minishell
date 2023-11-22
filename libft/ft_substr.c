/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:26:59 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:22:06 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || ft_strlen(s) == 0 || len <= 0)
	{
		ret = (char *)malloc(1);
		if (!ret)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

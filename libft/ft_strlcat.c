/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:11:34 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:23:16 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	total_len;
	size_t	i;
	size_t	j;

	j = 0;
	dest_len = 0;
	while (dest[dest_len] && dest_len < dstsize)
		dest_len++;
	if (dest_len < dstsize)
		total_len = dest_len + ft_strlen(src);
	else
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] && (dest_len + 1) < dstsize)
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (total_len);
}

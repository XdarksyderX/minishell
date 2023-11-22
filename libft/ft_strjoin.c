/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:18 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:23:21 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;
	char	*start;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = malloc(len_s1 + len_s2 + sizeof(char));
	if (!ret)
		return (NULL);
	start = ret;
	while (len_s1--)
		*ret++ = *s1++;
	while (len_s2--)
		*ret++ = *s2++;
	*ret = '\0';
	return (start);
}

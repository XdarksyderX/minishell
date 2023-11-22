/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:30:08 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/22 12:25:21 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num = -num;
		len = 1;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	long	ln;

	ln = n;
	len = num_len(ln);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	else if (n < 0)
	{
		ret[0] = '-';
		ln = -ln;
	}
	while (ln > 0)
	{
		ret[--len] = '0' + ln % 10;
		ln = ln / 10;
	}
	return (ret);
}

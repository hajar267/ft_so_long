/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:43:37 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/10 15:16:12 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cont_int(int nmb)
{
	int	i;

	i = 0;
	if (nmb < 0)
	{
		nmb = -nmb;
		i++;
	}
	while (nmb >= 1)
	{
		nmb = nmb / 10;
		i++;
	}
	return (i);
}

int	neg_place(char	*str, int n)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len ;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = cont_int(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	n = neg_place(str, n);
	str[len] = '\0';
	while (n > 9)
	{
		str[len -1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (n <= 9)
		str[len - 1] = n + '0';
	return (str);
}

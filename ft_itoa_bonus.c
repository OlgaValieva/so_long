/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:02 by carys             #+#    #+#             */
/*   Updated: 2022/02/19 15:07:06 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count(int n, int len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_exclusion(int v, char *dst, int i)
{
	if (v == -2147483648)
	{
		dst[i] = '-';
		dst[i + 1] = '2';
		v = 147483648;
		return (v);
	}
	else if (v < 0)
	{
		dst[i] = '-';
		v = v * -1;
		return (v);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		len;
	int		i;
	int		v;

	len = 0;
	i = 0;
	if (n <= 0)
		len = 1;
	v = n;
	len = ft_count(n, len);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	if (ft_exclusion(v, dst, i))
		v = ft_exclusion(v, dst, i);
	i = len - 1;
	while (v > 9)
	{
		dst[i--] = v % 10 + 48;
		v = v / 10;
	}
	dst[i] = v % 10 + 48;
	dst[len] = '\0';
	return (dst);
}

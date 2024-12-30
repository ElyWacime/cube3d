/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:18:30 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 16:32:11 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n, int *sign)
{
	int	count;

	count = 0;
	*sign = 1;
	if (n < 0)
		*sign = -1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		sign; 

	sign = 1;
	i = ft_size(n, &sign) + (sign == -1);
	p = ft_calloc(i + 1, 1);
	if (p == NULL)
		return (NULL);
	if (n == 0)
		p[--i] = '0';
	while (n != 0)
	{
		p[--i] = ((n % 10) * sign) + 48;
		n /= 10;
	}
	if (sign == -1)
		p[--i] = '-';
	return (p);
}

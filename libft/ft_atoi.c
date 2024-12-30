/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:09 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/23 13:11:35 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(unsigned long long int x, int sign, char str)
{
	unsigned long long int	max;

	max = 922337203685477580;
	if ((sign == 1) && ((x == max && (str == '8' || str == '9')) || x > max))
		return (-1);
	if ((sign == -1) && ((x == max && (str == '9')) || x > max))
		return (0);
	return (2);
}

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	x;

	x = 0;
	sign = 1;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		if (ft_check(x, sign, *str) != 2)
			return (ft_check(x, sign, *str));
		x = (10 * x) + (*str - 48);
		str++;
	}
	return ((int)x * sign);
}

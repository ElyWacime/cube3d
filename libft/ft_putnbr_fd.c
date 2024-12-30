/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:14:53 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/18 19:58:09 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				n = -n;
			}
			if (n < 10)
				ft_putchar_fd(n + 48, fd);
			else
			{
				ft_putnbr_fd((n / 10), fd);
				ft_putnbr_fd((n % 10), fd);
			}
		}
	}
}

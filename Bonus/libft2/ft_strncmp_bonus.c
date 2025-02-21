/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:59:14 by welyousf          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:34 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0 || !s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	if (i == n)
		return ((int)(*(unsigned char *)(s1 + i - 1) - *(unsigned char *)(s2 + i
					- 1)));
	return ((int)(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}

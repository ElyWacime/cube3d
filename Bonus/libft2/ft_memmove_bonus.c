/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:03:44 by welyousf          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:34 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long long	i;

	if (dst == 0 && src == 0)
		return (NULL);
	i = (long long)len;
	if (src < dst)
	{
		while (i > 0)
		{
			*(unsigned char *)(dst + (i - 1)) = *(unsigned char *)(src + (i
						- 1));
			i--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}

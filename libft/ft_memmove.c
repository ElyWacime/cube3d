/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:22:39 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/18 17:28:10 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (src == dst)
		return (dst);
	x = dst <= src;
	while (i < len)
	{
		*(unsigned char *)(dst + (i * x) + (len - (1 + i)) * (1
					- x)) = *(unsigned char *)(src + (i * x) + (len - (1 + i))
				* (1 - x));
		i++;
	}
	return (dst);
}

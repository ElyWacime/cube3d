/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:34:30 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 18:33:48 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	nd;
	size_t	ns;
	size_t	i;
	size_t	odstsize;

	nd = 0;
	odstsize = dstsize;
	ns = ft_strlen(src);
	while (dstsize > 0 && dst[nd] != '\0')
	{
		nd++;
		dstsize--;
	}
	if (dst[nd] != '\0' && dstsize == 0)
		return (ns + odstsize);
	i = 0;
	while (i + nd + 1 < odstsize && i < ns)
	{
		dst[nd + i] = src[i];
		i++;
	}
	dst[nd + i] = '\0';
	i = (odstsize <= nd);
	return (ns + (i * odstsize) + ((1 - i) * nd));
}

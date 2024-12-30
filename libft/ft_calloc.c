/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:24:40 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 19:51:29 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (count != 0 && size != 0)
	{
		if (size > 9223372036854775807 / count)
			return (NULL);
	}
	p = (void *)malloc((count * size));
	i = 0;
	if (p != NULL)
		return (ft_memset(p, 0, count * size));
	return (p);
}

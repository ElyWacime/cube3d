/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:12:24 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 20:39:04 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	x;

	if (s == NULL)
		return (NULL);
	len = (ft_strlen(s) * (len >= ft_strlen(s))) + ((1 - (len >= ft_strlen(s)))
			* len);
	if (start < ft_strlen(s) && ft_strlen(s) > 0)
	{
		x = (len <= ft_strlen(s) - start);
		sub = (char *)ft_calloc(((len * x) + ((1 - x) * (ft_strlen(s) - start))
					+ 1), sizeof(char));
		if (sub != NULL)
		{
			ft_strlcpy(sub, s + start, len + 1);
			return (sub);
		}
		return (NULL);
	}
	sub = (char *)ft_calloc(1, 1);
	if (sub == NULL)
		return (NULL);
	return (sub);
}

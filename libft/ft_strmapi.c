/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:54:21 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 21:30:54 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	p = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	i = 0;
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:51 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 20:48:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	n = ft_strlen(s1);
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	if (i == n)
		return (ft_strdup(s1 + n));
	while (n > 0)
	{
		if (ft_strchr(set, s1[n - 1]) == NULL)
			break ;
		n--;
	}
	return (ft_substr(s1, i, n - i));
}

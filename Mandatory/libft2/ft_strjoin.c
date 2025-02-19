/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:14:20 by welyousf          #+#    #+#             */
/*   Updated: 2024/07/08 15:00:46 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*ret;
	size_t	s1len;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s2 == NULL && s1 != NULL)
	{
		ret = ft_strdup(s1);
		free((char *)s1);
		return (ret);
	}
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	s1len = ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, s1len + ft_strlen(s2) + 1);
	free((char *)s1);
	return (str);
}

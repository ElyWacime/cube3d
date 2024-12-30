/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:36 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 20:42:16 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	n1;
	size_t	n2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	join = (char *)ft_calloc((n1 + n2 + 1), sizeof(char));
	if (join != NULL)
	{
		ft_strlcpy(join, s1, n1 + 1);
		ft_strlcat(join, s2, n1 + n2 + 1);
		return (join);
	}
	return (NULL);
}

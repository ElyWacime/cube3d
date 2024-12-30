/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:55:39 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/06 12:55:41 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)n)
			return ((char *)(str + i));
		i++;
	}
	if ((char)n != '\0')
		return (NULL);
	return ((char *)(str + i));
}

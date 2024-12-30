/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:55 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/06 12:55:00 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (str[i] != '\0')
	{
		if ((char)n == str[i])
			last = i;
		i++;
	}
	if (last == -1 && (char)n != '\0')
		return (NULL);
	if (last >= 0)
		return ((char *)(str + last));
	return ((char *)(str + i));
}

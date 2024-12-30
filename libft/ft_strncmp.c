/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:35:29 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 18:50:09 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	n2;
	size_t	n1;

	n2 = ft_strlen(s1);
	n1 = ft_strlen(s2);
	if (n == 0)
		return (0);
	if (n1 < n2)
		n2 = n1;
	n1 = 0;
	while (n1 < n2 && n1 + 1 < n)
	{
		if (s1[n1] != s2[n1])
			return (((unsigned char)s1[n1] - (unsigned char)s2[n1]));
		n1++;
	}
	return (((unsigned char)s1[n1] - (unsigned char)s2[n1]));
}

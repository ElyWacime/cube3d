/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:44:56 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 20:45:41 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	char	flag;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (c == '\0' && *s != '\0')
		return (1);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == c))
			i++;
		flag = '0';
		while (s[i] != '\0' && s[i] != c)
		{
			flag = '1';
			i++;
		}
		if (flag == '1')
			len++;
	}
	return (len);
}

static size_t	ft_wordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && (s[i] != c))
		i++;
	return (i);
}

static char	*ft_scopy(char *s, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i];
		i++;
	}
	return (sub);
}

static char	**ft_free(char **sub, size_t i, int f)
{
	if (f == 0)
	{
		while (i >= 0)
		{
			free(sub[i]);
			if (i == 0)
				break ;
			i--;
		}
		free(sub);
		return (NULL);
	}
	else if (sub != NULL)
		sub[i] = NULL;
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**sub;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_count((char *)s, c);
	sub = (char **)malloc((sizeof(char *) * (len + 1)));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		while (*s != '\0' && (*s == c))
			s++;
		if (*s != '\0')
			sub[i] = ft_scopy((char *)s, ft_wordlen((char *)s, c));
		if (sub[i++] == NULL)
			return (ft_free(sub, i - 1, 0));
		while (*s != '\0' && (*s != c))
			s++;
	}
	ft_free(sub, len, 1);
	return (sub);
}
